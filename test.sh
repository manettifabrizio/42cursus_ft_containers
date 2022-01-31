#!/usr/bin/env bash

CC="clang++"
CFLAGS="-Wall -Wextra -Werror -std=c++98"
FSANITIZE="-fsanitize=address -g3 -O0"

INCL_PATH="../"
TESTER_FOLDER="test"
TESTS_FOLDER="$TESTER_FOLDER/srcs"
LOG_FOLDER="$TESTER_FOLDER/logs"
DIFF_FOLDER="$TESTER_FOLDER/diff"
EXEC_FOLDER="$TESTER_FOLDER/tmp"

RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"

display_figlet ()
{
	printf "$GREEN"
	printf "    ______                       __        _                      \n"
	printf "   / __/ /_    _________  ____  / /_____ _(_)___  ___  __________ \n"
	printf "  / /_/ __/   / ___/ __ \/ __ \/ __/ __ '/ / __ \/ _ \/ ___/ ___/ \n"
	printf " / __/ /_    / /__/ /_/ / / / / /_/ /_/ / / / / /  __/ /  (__  )  \n"
	printf "/_/  \__/____\___/\____/_/ /_/\__/\__,_/_/_/ /_/\___/_/  /____/   \n"
	printf "       /_____/                                                    \n"
	printf "$RESET"
	printf " ___         __                     _   _   _  \n"
	printf "| _ )_  _   / _|_ __  __ _ _ _  ___| |_| |_(_) \n"
	printf "| _ \ || | |  _| '  \/ _' | ' \/ -_)  _|  _| | \n"
	printf "|___/\_, | |_| |_|_|_\__,_|_||_\___|\__|\__|_| \n"
	printf "     |__/                                      \n"
}

compile ()
{
	# 1=file 2=define used {ft/std} 3=output_file
	$CC $CFLAGS -o "$3" -I . -D TESTED_NAMESPACE=$2 $FSANITIZE $1
	return $?
}

display ()
{
	# 1=file 2=compile 3=output 4=std_time 5=ft_time
	b[0]="✅"; b[1]="❌";

	printf "%-35s: COMPILE: ${b[$2]} | OUT: ${b[$3]} | STD_TIME: $4 | FT_TIME: $5\n" $1
}

test () {
	TEST_FILES=`cd $TESTS_FOLDER/$container/ ; ls $1 | grep "cpp"`

	rm -f $DIFF_FOLDER/*.diff $LOG_FOLDER/*.log

	for file in ${TEST_FILES[@]}; do
		
		testname=$(echo $file | cut -d "." -f 1)
		ft_log="$LOG_FOLDER/ft.$testname.$container.log"
		std_log="$LOG_FOLDER/std.$testname.$container.log"
		ft_exec="$EXEC_FOLDER/ft.$container.$testname"
		std_exec="$EXEC_FOLDER/std.$container.$testname"

		compile "$TESTS_FOLDER/$container/$file" "ft" $ft_exec; ft_ret=$?
		compile "$TESTS_FOLDER/$container/$file" "std" $std_exec

		if [ $ft_ret -eq 0 ]; then
			compilation=0
		else
			compilation=1
		fi

		exec 3>&1 4>&2
		std_time=$(TIMEFORMAT="%R"; { time ./$std_exec > $std_log 2>&4; std_ret=$?; } 2>&1)
		ft_time=$(TIMEFORMAT="%R"; { time ./$ft_exec > $ft_log 2>&4; ft_ret=$?; } 2>&1)
		exec 3>&- 4>&-

		if [ $ft_ret -eq 0 ]; then
			compilation=0
		else
			compilation=1
		fi

		if [ $compilation -eq 0 ]; then
			diff_file="$DIFF_FOLDER/$testname.$container.diff"
			diff $std_log $ft_log 2>/dev/null 1>"$diff_file";
			output=$?
		else
			output=1
		fi

		# If there is no diff delete all test related files
		[ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null

		rm -rf $ft_exec* $std_exec* $EXEC_FOLDER/*.dSYM $container.hpp.gch &>/dev/null

		display "$container/$file" $compilation $output $std_time $ft_time

	done
}

# Usage

## All containers
# ./test.sh

## Specific containers
# ./test.sh <container> <container1>

## One test
# ./test.sh -o <container> <file>

## Clean files
#./test.sh -c

mkdir $EXEC_FOLDER $LOG_FOLDER $DIFF_FOLDER &> /dev/null

if [ $# -eq 0 ]; then

	display_figlet

	containers=(vector map stack)

	for container in ${containers[@]}; do
		printf "ft_%s\n" $container
		test
	done
else
	if [ $1 = "-o" ]; then
		display_figlet
		container=$2
		test $3
	elif [ $1 = "-c" ]; then
		rm -rf $DIFF_FOLDER/*.diff $LOG_FOLDER/*.log $EXEC_FOLDER/*.dSYM *.dSYM .vscode a.out
	else
		display_figlet
		containers=($@);

		for container in ${containers[@]}; do
			printf "ft_%s\n" $container
			test
		done
	fi
fi