/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/11 15:34:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( TESTED_NAMESPACE::pair<const char,int>('a',100) );
	mymap.insert ( TESTED_NAMESPACE::pair<const char,int>('z',200) );

	display_m(mymap, "mymap");

	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( TESTED_NAMESPACE::pair<const char,int>('z',500) );
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.second << '\n';
	}

	// // second insert function version (with hint position):
	// TESTED_NAMESPACE::map<char,int>::iterator it = mymap.begin();
	// mymap.insert (it, TESTED_NAMESPACE::pair<const char,int>('b',300));  // max efficiency inserting
	// mymap.insert (it, TESTED_NAMESPACE::pair<const char,int>('c',400));  // no max efficiency inserting

	// display_m(mymap, "mymap");

	// // third insert function version (range insertion):
	// TESTED_NAMESPACE::map<char,int> anothermap;
	// anothermap.insert(mymap.begin(),mymap.find('c'));

	// display_m(anothermap, "anothermap");

	// // showing contents:
	// std::cout << "mymap contains:\n";
	// for (it=mymap.begin(); it!=mymap.end(); ++it)
	// std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "anothermap contains:\n";
	// for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	// std::cout << it->first << " => " << it->second << '\n';

	return 0;
}