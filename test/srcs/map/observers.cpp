/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:54:02 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:30:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;

	TESTED_NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	TESTED_NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	TESTED_NAMESPACE::map<char,int> mymap1;

	mymap1['x']=1001;
	mymap1['y']=2002;
	mymap1['z']=3003;

	std::cout << "mymap1 contains:\n";

	std::pair<char,int> highest = *mymap1.rbegin();          // last element

	TESTED_NAMESPACE::map<char,int>::iterator it = mymap1.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap1.value_comp()(*it++, highest) );

	return 0;
}