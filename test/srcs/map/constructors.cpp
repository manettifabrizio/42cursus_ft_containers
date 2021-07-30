/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:55:19 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:30:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
	TESTED_NAMESPACE::map<char,int> first;

	display_m(first, "first");

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	display_m(first, "first");

	TESTED_NAMESPACE::map<char,int> second (first.begin(),first.end());

	display_m(second, "second");

	TESTED_NAMESPACE::map<char,int> third (second);

	display_m(third, "third");

	TESTED_NAMESPACE::map<char,int,classcomp> fourth;                 // class as Compare

	display_m(fourth, "fourth");

	bool(*fn_pt)(char,char) = fncomp;
	TESTED_NAMESPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	display_m(fifth, "fifth");

	return 0;
}