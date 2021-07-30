/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:36:40 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

void		_int()
{
	TESTED_NAMESPACE::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	display(myvector, "myvector");

	myvector.clear();

	display(myvector, "myvector");

	myvector.push_back (1101);
	myvector.push_back (2202);

	display(myvector, "myvector");
}

void		_string()
{
	TESTED_NAMESPACE::vector<std::string> myvector;
	myvector.push_back ("ciao");
	myvector.push_back ("come");
	myvector.push_back ("va");

	display(myvector, "myvector");

	myvector.clear();

	display(myvector, "myvector");

	myvector.push_back ("io");
	myvector.push_back ("molto");

	display(myvector, "myvector");
}

void		_class()
{
	TESTED_NAMESPACE::vector<A> myvector;
	myvector.push_back (A(1, 2, "ciao"));
	myvector.push_back (A(2, 4, "come"));
	myvector.push_back (A(3, 5, "va"));

	display(myvector, "myvector");

	myvector.clear();

	display(myvector, "myvector");

	myvector.push_back (A(3, 5, "va"));
	myvector.push_back (A(3, 5, "va"));

	display(myvector, "myvector");
}

int main ()
{
	_int();
	_string();
	_class();

	return 0;
}