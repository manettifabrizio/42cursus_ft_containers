/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:19:24 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

void		_int()
{
	TESTED_NAMESPACE::vector<int> myvector (3,100);
	TESTED_NAMESPACE::vector<int>::iterator it;

	display(myvector, "myvector");

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");

	myvector.insert (it, 2, 300);

	display(myvector, "myvector");

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	TESTED_NAMESPACE::vector<int> anothervector (2,400);
	
	display(anothervector, "anothervector");

	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	display(anothervector, "anothervector");

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	display(myvector, "myvector");
}

void		_string()
{
	TESTED_NAMESPACE::vector<std::string> myvector (3, "ciao");
	TESTED_NAMESPACE::vector<std::string>::iterator it;

	display(myvector, "myvector");

	it = myvector.begin();
	it = myvector.insert (it, "mamma");

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");

	myvector.insert (it, 2, "parco");

	display(myvector, "myvector");

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	TESTED_NAMESPACE::vector<std::string>	anothervector(2, "toto");
	
	display(anothervector, "anothervector");

	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	display(anothervector, "anothervector");

	std::string myarray [] = { "ciao", "come", "va" };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	display(myvector, "myvector");
}

void		_class()
{
	A		x(1, 1.0, "vector");
	A		y(2, 2.0, "stack");
	A		z(3, 3.0, "deque");
	A		c(4, 4.0, "map");

	TESTED_NAMESPACE::vector<A> myvector (3, x);
	TESTED_NAMESPACE::vector<A>::iterator it;

	display(myvector, "myvector");

	it = myvector.begin();
	it = myvector.insert (it, y);

	std::cout << "return:" << *it << std::endl;

	display(myvector, "myvector");

	myvector.insert (it, 2, z );

	display(myvector, "myvector");

	myvector.insert (myvector.begin() + 6, 2, z );

	display(myvector, "myvector");

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	TESTED_NAMESPACE::vector<A> anothervector (2, c);
	
	display(anothervector, "anothervector");

	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	display(anothervector, "anothervector");

	A myarray [] = { x, y, z, c };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	display(myvector, "myvector");
}

int main ()
{
	_int();
	_string();
	_class();

	return 0;
}