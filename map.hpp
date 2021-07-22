/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:04:46 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/22 16:27:09 by fmanetti         ###   ########.fr       */
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
	template < class Key, class T >
	struct s_tree
	{
		ft::pair<const Key, T>	data;
		struct s_tree			*left;
		struct s_tree			*right;
	};

	template <	class Key,												// map::key_type
				class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
			>
	class map
	{
		private:

			typedef typename ft::s_tree<T>						tree_node;		

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

			/*							MEMBER VARIABLES						*/

			tree_node											*_root;
			size_type											_size;
			size_type											_capacity;
			key_compare											_comp;
			allocator_type										_all;

			/*							TREE UTILITIES							*/

			tree_node					*newNode( value_type data )
			{
				tree_node		*n;

				n = _all.allocate(1);

				_all.construct(&(n->data), data);

				n->left = nullptr;
				n->right = nullptr;

				return (n);
			}
		
		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/*	First (Default constructor)
				Empty container, no elements.									*/
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_root(nullptr), _size(0), _capacity(0), __comp(comp), _all(alloc)
			{
			}

			/*	Second (Range constructor)
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range.							*/
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_size(last - first), _capacity(compute)
			{
			}

			/*	Third (Copy constructor)
				Constructs a container with a copy of each of the elements
				in x.															*/
			map (const map& x)
			{
			}
	};
}

#endif