/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:53:47 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/09 18:36:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "../vector/Vector.hpp"

int				main()
{
	int		a[] = {0, 1, 2, 3, 4, 5, 6};

	std::vector<int>				v(a, a + 7);
	std::vector<int>::iterator		it;

	ft::Vector<int>					v1(a, a + 7);

	return (0);
}