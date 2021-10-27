/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:56:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/27 19:58:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.hpp"

int		main()
{

	std::list<int> lst(10);

	int i = 0;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		*it = i;
		i++;
	}

	std::cout << "===copy constructor with list as underlying container===" << std::endl;
	TESTED_NAMESPACE::stack<int, std::list<int> > stk3(lst);

	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;
	
	stk3.push(42);;
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.push(21);
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	stk3.pop();
	std::cout << "size = " << stk3.size() << " _ empty = " << stk3.empty() << " _ top = " << stk3.top() << std::endl;

	return (0);
}