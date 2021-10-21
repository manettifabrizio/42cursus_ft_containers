/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:45 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/21 11:31:16 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;
	TESTED_NAMESPACE::map<char,int>::iterator it;

	// insert some values:
	mymap['b'] = 20;
	mymap['d'] = 10;
	mymap['f'] = 30;
	mymap['e'] = 40;
	mymap['c'] = 50;
	mymap['g'] = 60;

	display_m(mymap, "mymap");

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	display_m(mymap, "mymap");

	mymap.erase ('y');                  // erasing by key that doesn't exist
	mymap.erase ('c');                  // erasing by key

	display_m(mymap, "mymap");

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	TESTED_NAMESPACE::map<char,int> mymap2;

	// insert some values:
	mymap2['d'] = 20;
	mymap2['b'] = 10;
	mymap2['c'] = 30;
	mymap2['f'] = 40;
	mymap2['e'] = 50;
	mymap2['a'] = 60;

	display_m(mymap2, "mymap2");

	it=mymap2.find('b');
	mymap2.erase (it);                   // erasing by iterator

	display_m(mymap2, "mymap2");

	mymap2.erase ('y');                  // erasing by key that doesn't exist
	mymap2.erase ('c');                  // erasing by key

	display_m(mymap2, "mymap2");

	it=mymap2.find ('c');
	mymap2.erase ( it, mymap2.end() );    // erasing by range

	// show content:
	for (it=mymap2.begin(); it!=mymap2.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	return 0;
}