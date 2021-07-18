/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:08:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
	myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	return 0;
}