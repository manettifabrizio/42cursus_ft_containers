/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:53:47 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/12 19:16:43 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "../vector/Vector.hpp"

int				main()
{
	// int		a[] = {0, 1, 2, 3, 4, 5, 6};

	// int		*b;

	std::vector<int>	v;

	long long c = v.max_size() + 1;

	std::vector<int>	v1(c, 1);

	for (long long x = 0; x <= c; x++)
	{
		v.push_back(x);

		// std::cout << "size: " << v.size() << "capacity: " << v.capacity() << std::endl;

	}
	return (0);
}