/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:55 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/21 15:41:09 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	int i;
	TESTED_NAMESPACE::map<int,int> mymap;

	if (mymap.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
		{
			mymap[i] = 0;
		}
		std::cout << "The map contains 1000 elements.\n";
	}
	else
		std::cout << "The map could not hold 1000 elements.\n";

	return 0;
}