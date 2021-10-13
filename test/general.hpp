/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../general.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:16:03 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 01:06:15 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_HPP
# define GENERAL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "../vector.hpp"
#include "../map.hpp"

# ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

class A
{
	public:

		A( void ) {};
		A( int n, float f, std::string s ) : _n(n), _f(f), _s(s) {}
		virtual	~A( void ) {};

		int						getInt( void ) const { return _n; }
		float					getFloat( void ) const { return _f; }
		std::string				getString( void ) const { return _s; }

	private:

		int						_n;
		float					_f;
		std::string				_s;

};

std::ostream					&operator<<( std::ostream &o, const A &rhs )
{
	o	<< "int: " << rhs.getInt() << std::endl
		<< "float: " << rhs.getFloat() << std::endl
		<< "string: " << rhs.getString() << std::endl << std::endl;

	return (o);
}

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

template < class T >
void			display_m( T &m, std::string s )
{
	std::cout << s << std::endl;

	// std::cout << "head:" << m.begin()->first << "=>" << m.begin()->second << std::endl;

	for (typename T::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << ' ' << it->second
					<< std::endl;
}

#endif