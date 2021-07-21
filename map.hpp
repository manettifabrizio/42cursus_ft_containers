/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:04:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 19:21:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <map>
#include <memory>

#include "map/utility.hpp"

namespace ft
{
	template < typename T >
	struct s_tree
	{
		T data;
		struct s_tree *left;
		struct s_tree *right;	
	};

	template <	class Key,												// map::key_type
				class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T>>		// map::allocator_type
			>
	class map
	{
		public:

			/*							MEMBER TYPES							*/

			typedef Key											key_type;
			typedef	T											mapped_type;
			typedef ft::pair<const Key,T>						value_type;
			typedef Compare										key_compare;
			typedef ciao										value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	ft::iterator<T>								iterator;
			typedef ft::const_iterator<T>						const_iterator;
			typedef ft::reverse_iterator<T>						reverse_iterator;
			typedef	const ft::reverse_iterator<T>				const_reverse_iterator;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

		private:

			/*							VARIABLES								*/

			
		
		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

	};
}

#endif