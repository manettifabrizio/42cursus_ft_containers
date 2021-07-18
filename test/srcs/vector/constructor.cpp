/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:39:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/17 23:37:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	// constructors used in the same order as described above:
	TESTED_NAMESPACE::vector<int> first;                                // empty vector of ints
	TESTED_NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
	TESTED_NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
	TESTED_NAMESPACE::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	TESTED_NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	display(first, "first");
	display(second, "second");
	display(third, "third");
	display(fourth, "fourth");
	display(fifth, "fifth");

	return 0;
}