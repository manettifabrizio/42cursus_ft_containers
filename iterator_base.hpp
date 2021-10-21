/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:40:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/21 15:59:25 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP

#include <iostream>
#include <iterator>

namespace ft
{
	/*
		Traits class defining properties of iterators.
	*/

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
    	typedef typename Iterator::value_type			value_type;
    	typedef typename Iterator::pointer				pointer;
    	typedef typename Iterator::reference			reference;
    	typedef typename Iterator::iterator_category	iterator_category;
	};

	/*
		Case in which the iterator is a pointer or const pointer
		(random access iterator)
	*/

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	/*				-|-|-|-|- RELATIONAL OPERATORS -|-|-|-|-				*/

	template < class Iter >
	bool							operator==( const Iter &x, const Iter &y )
	{
		return ( x.base() == y.base() );
	}
	
	template < class Iter >
	bool							operator!=( const Iter &x, const Iter &y )
	{
		return !( x == y );
	}

	template < class Iter >
	bool							operator<( const Iter &x, const Iter &y )
	{
		return ( x.base() < y.base() );
	}
	
	template < class Iter >
	bool							operator>( const Iter &x, const Iter &y )
	{
		return ( y < x );
	}
	
	template < class Iter >
	bool							operator<=( const Iter &x, const Iter &y )
	{
		return !( x > y );
	}
	
	template < class Iter >
	bool							operator>=( const Iter &x, const Iter &y )
	{
		return !( y < x );
	}

	template < class Iter >
	Iter							operator+( const Iter &x, const ptrdiff_t n )
	{
		x += n;

		return ( x );
	}

	template < class Iter >
	ptrdiff_t						operator-( const Iter &x, const Iter &y )
	{
		return ( x.base() - y.base() );
	}

}

#endif