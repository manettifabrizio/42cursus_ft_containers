/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:26:50 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:07:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

#include <iostream>
#include <vector>

int main ()
{
	TESTED_NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	TESTED_NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

	display(foo, "foo");
	display(bar, "bar");

	foo.swap(bar);

	display(foo, "foo");
	display(bar, "bar");

	swap(foo, bar);

	display(foo, "foo");
	display(bar, "bar");

	return 0;
}