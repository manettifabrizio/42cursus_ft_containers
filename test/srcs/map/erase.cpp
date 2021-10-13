/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:45 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/13 16:11:37 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;
	TESTED_NAMESPACE::map<char,int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	display_m(mymap, "mymap");

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	display_m(mymap, "mymap");

	mymap.erase ('c');                  // erasing by key

	display_m(mymap, "mymap");

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	return 0;
}