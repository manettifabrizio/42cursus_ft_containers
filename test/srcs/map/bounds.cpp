/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:21 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/26 19:27:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;
	TESTED_NAMESPACE::map<char,int>::iterator itlow,itup;

	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['a'] = 20;
	mymap['e'] = 100;
	mymap['b'] = 40;
	mymap['1'] = 200;

	display_m(mymap, "mymap");

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "itlow: " << itlow->first << std::endl;
	std::cout << "itup: " << itup->first << std::endl;

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	display_m(mymap, "mymap");

	return (0);
}