/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:50:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/20 15:49:17 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	int		a[] = {0, 1, 2, 3, 4};

	TESTED_NAMESPACE::vector<int> myvector (a, a + 5);  // 5 default-constructed ints

	int i = 0;

	TESTED_NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();

	std::cout << "rbegin: " << *rit << std::endl;

	display(myvector, "myvector");

	for (; rit != myvector.rend(); ++rit)
		*rit = ++i;

	display(myvector, "myvector");

	return 0;
}