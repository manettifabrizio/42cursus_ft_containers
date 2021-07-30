/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:39:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	// constructors used in the same order as described above:
	TESTED_NAMESPACE::vector<int> first;                                // empty vector of ints
	TESTED_NAMESPACE::vector<std::string> second (4, "toto");                       // four ints with value 100
	TESTED_NAMESPACE::vector<std::string> third (second.begin(),second.end());  // iterating through second
	TESTED_NAMESPACE::vector<std::string> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	A myclasses[] = { A(1, 2.0f, "ciao"), A(1, 3.0, "mamma") };
	TESTED_NAMESPACE::vector<A> fifth (myclasses, myclasses + sizeof(myclasses) / sizeof(A) );

	display(first, "first");
	display(second, "second");
	display(third, "third");
	display(fourth, "fourth");
	display(fifth, "fifth");

	return 0;
}