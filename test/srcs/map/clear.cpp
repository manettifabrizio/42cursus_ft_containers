/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:53:28 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/27 18:09:18 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	display_m(mymap, "mymap");

	mymap.clear();

	display_m(mymap, "mymap");
	
	mymap['a']=1101;
	mymap['b']=2202;

	display_m(mymap, "mymap");

	return 0;
}