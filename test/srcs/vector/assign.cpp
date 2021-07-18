/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:09:13 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
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

	return 0;
}