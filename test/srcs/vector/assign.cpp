/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:09:13 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/20 21:19:47 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

void		_int()
{
	TESTED_NAMESPACE::vector<int> first;
	TESTED_NAMESPACE::vector<int> second;
	TESTED_NAMESPACE::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	display(first, "first");

	TESTED_NAMESPACE::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	display(second, "second");

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	display(third, "third");
}

void		_string()
{
	TESTED_NAMESPACE::vector<std::string> first;
	TESTED_NAMESPACE::vector<std::string> second;

	first.assign (7, "ciao");

	display(first, "first");

	TESTED_NAMESPACE::vector<std::string>::iterator it;
	it = first.begin() + 1;

	first.assign (it, first.end() - 1); // the 5 central values of first

	display(first, "first");

	std::string mys[] = {"ciao", "come", "va"};
	second.assign (mys, mys+3);   // assigning from array.

	display(second, "second");
}

void		_class()
{
	A	x(1, 2.0f, "ciao");	

	TESTED_NAMESPACE::vector<A> first;
	TESTED_NAMESPACE::vector<A> second;

	first.assign (7, x);

	display(first, "first");

	TESTED_NAMESPACE::vector<A>::iterator it;
	it=first.begin()+1;

	first.assign (it,first.end()-1); // the 5 central values of first

	display(first, "first");

	A mys[] = {A(1, 2.0f, "ciao"), A(2, 3.0f, "come"), A(3, 4.0f, "va")};
	second.assign (mys, mys + 3);   // assigning from array.

	display(second, "second");
}

int main ()
{
	_int();
	_string();
	_class();

	return 0;
}