/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:22:15 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	display(myvector, "myvector");

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	display(myvector, "myvector");

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	display(myvector, "myvector");

	return 0;
}