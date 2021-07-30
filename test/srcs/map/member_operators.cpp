/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_operators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:59 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:30:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> first;
	TESTED_NAMESPACE::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	display_m(first, "first");

	second=first;                // second now contains 3 ints

	display_m(second, "second");

	first=TESTED_NAMESPACE::map<char,int>();  // and first is now empty

	display_m(first, "first");

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
	return 0;
}