/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:51:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 00:45:21 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.hpp"

#include <iostream>
#include <vector>

int main ()
{
  TESTED_NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

  TESTED_NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();

  int i=0;
  for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}