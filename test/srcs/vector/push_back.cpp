/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:11:03 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> myvector;
	
	for (int i = 0; i < 20; i++)
		myvector.push_back(i + 1);

	display(myvector, "myvector");

	for (int i = 50; i < 55; i++)
		myvector.push_back(i + 1);

	display(myvector, "myvector");

	return 0;
}