/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:40:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/11/03 18:14:35 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP

#include <iostream>
#include <iterator>
#include <cstddef>

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

	/*			-|-|-|-|- ALGORYTHMS FOR RELATIONAL OPERATORS -|-|-|-|-			*/

	template <class InputIterator1, class InputIterator2>
	bool 					equal ( InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}

		return (true);
	}

	template <class InputIterator1, class InputIterator2>
  	bool					lexicographical_compare( InputIterator1 first1,
		InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}

		return (first2 != last2);
	}

}

#endif