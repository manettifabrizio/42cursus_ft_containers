/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:53:47 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/13 16:29:23 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "../vector/vector.hpp"

/*
	push_back (cap * 2)
	insert (cap * 2) if need still more
*/

int				main()
{

	int							a[] = {0, 1, 2, 3, 4};
	std::vector<int>			v1;
	std::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << "STD_VECTOR" << std::endl;

	std::cout << "Start: " << std::endl;
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	it1 = v1.begin();

	v1.insert(it1, 4);

	std::cout << "Insert I: " << std::endl;
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	it1 = v1.begin();

	v1.insert(it1 + 1, 5, 9);

	std::cout << "Insert II: " << std::endl;
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	it1 = v1.begin();

	v1.insert(it1 + 2, a, a + 4);

	std::cout << "Insert III: " << std::endl;
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "FT_VECTOR" << std::endl;

	std::cout << "Start: " << std::endl;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	v.insert(v.begin(), 4);

	std::cout << "Insert I: " << std::endl;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	v.insert(v.begin() + 1, 5, 9);

	std::cout << "Insert II: " << std::endl;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	v.insert(v.begin() + 2, a, a + 4);

	std::cout << "Insert III: " << std::endl;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	
	return (0);
}