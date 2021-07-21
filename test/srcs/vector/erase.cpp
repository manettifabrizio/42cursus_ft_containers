/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:22:15 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/21 13:18:37 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

void			_int()
{
	TESTED_NAMESPACE::vector<int>			myvector;
	TESTED_NAMESPACE::vector<int>::iterator	it;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	display(myvector, "myvector");

	it = myvector.erase (myvector.begin() + 6);

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");

	// erase the last element
	it = myvector.erase (myvector.begin() + 7);

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");

	// erase the first 3 elements:
	it = myvector.erase (myvector.begin(), myvector.begin() + 3);

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");
}

void			_string()
{
	TESTED_NAMESPACE::vector<std::string>			myvector;
	TESTED_NAMESPACE::vector<std::string>::iterator	it;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back("ciao");

	display(myvector, "myvector");

	// erase the 10th element
	it = myvector.erase (myvector.begin() + 9);

	display(myvector, "myvector");

	// erase the first 3 elements:
	it = myvector.erase (myvector.begin(), myvector.begin() + 3);

	display(myvector, "myvector");
}

void			_class()
{
	TESTED_NAMESPACE::vector<A>  myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(A(i, i + 1, "ciao"));

	display(myvector, "myvector");

	// erase the 10th element
	myvector.erase (myvector.begin() + 9);

	display(myvector, "myvector");

	// erase the first 3 elements:
	myvector.erase (myvector.begin(), myvector.begin() + 3);

	display(myvector, "myvector");
}

int main ()
{
	_int();
	_string();
	_class();

	return 0;
}