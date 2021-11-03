/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_operators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:36:55 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> foo (3,0);
	TESTED_NAMESPACE::vector<int> bar (5,0);

	bar = foo;
	foo = TESTED_NAMESPACE::vector<int>();

	display(foo, "foo");
	display(bar, "bar");
	
	TESTED_NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized elements
	TESTED_NAMESPACE::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++)
		myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	return 0;
}