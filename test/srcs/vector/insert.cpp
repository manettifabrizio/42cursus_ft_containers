/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:19:24 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> myvector (3,100);
	TESTED_NAMESPACE::vector<int>::iterator it;

	display(myvector, "myvector");

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	display(myvector, "myvector");

	myvector.insert (it, 2, 300);

	display(myvector, "myvector");

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	TESTED_NAMESPACE::vector<int> anothervector (2,400);
	
	display(anothervector, "anothervector");

	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	display(anothervector, "anothervector");

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	display(myvector, "myvector");

	return 0;
}