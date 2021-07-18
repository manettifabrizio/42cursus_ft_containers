/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:16:03 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/17 23:22:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_HPP
# define GENERAL_HPP

#include "vector.hpp"

# ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

template < typename T >
void			display( T x , std::string name )
{
	std::cout << name << std::endl;
	std::cout << "Size: " << x.size() << std::endl;

	std::cout << "Contents: ";
	for (typename T::iterator it = x.begin(); it != x.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

#endif