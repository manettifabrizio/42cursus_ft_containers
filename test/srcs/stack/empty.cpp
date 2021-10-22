/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:11:01 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/22 18:01:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int main ()
{
	TESTED_NAMESPACE::stack<int> mystack;

	int sum (0);

	for (int i = 1; i <= 10; i++)
		mystack.push(i);

	// display_s(mystack);

	while (!mystack.empty())
	{
		sum += mystack.top();
		std::cout << mystack.top() << " ";
		mystack.pop();
	}

	std::cout << std::endl;

	std::cout << "total: " << sum << '\n';

	return 0;
}