/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:55:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	display(myvector, "myvector");

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	display(myvector, "myvector after empty");

	std::cout << "total: " << sum << '\n';

	return 0;
}