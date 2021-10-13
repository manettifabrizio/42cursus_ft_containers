/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:12:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/13 15:20:26 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../iterator_base.hpp"

namespace ft {

	/*	Bidirectional Iterator class template
		Bidirectional iterators are iterators that can be used to access the
		sequence of elements in a range in both directions (towards the end
		and towards the beginning).
	*/

	template <	class T,
				class Node,
				class Category = std::bidirectional_iterator_tag,
				class Distance = ptrdiff_t,
				class Pointer = T*,
				class Reference = T& >
	class map_iterator
	{

		typedef T											value_type;
		typedef Node*	                                    node_pointer;
		typedef Distance									difference_type;
		typedef Pointer										pointer;
		typedef Reference									reference;
		typedef Category									iterator_category;

		public:

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			map_iterator( void ) : node(nullptr) { }

			map_iterator( node_pointer it ) : node(it) { }

			map_iterator( const map_iterator &src )
			{
				node = src.node;
			}

			~map_iterator( void ) { }

			node_pointer				base( void ) const
			{
				return (node);
			}

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (node->data);
			}

			pointer						operator->( void ) const
			{
				return (&(node->data));
			}

			/* Increment/Decrement												*/
			
			// prefix 
			map_iterator				&operator++( void )
			{
				//	Down to the right and left as possible
				if (node->right != nullptr)
					{
						node = node->right;

						while (node->left != nullptr)
							node = node->left;
					}
				// Move up the tree until we have moved over a
				// left child link
				else
				{
					node_pointer p = node->parent;
					while (p != nullptr && node == p->right)
					{
						node = p;
						p = p->parent;
					}

					node = p;
				}

				return (*this);
			}
		
			// postfix
			map_iterator				operator++( int )
			{
				map_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			map_iterator				&operator--( void )
			{
				//	One to the left and downode to right as possible
				if (node->left != nullptr)
				{
					node = node->left;

					while (node->right != nullptr)
						node = node->right;
				}
				// Move up the tree until we have moved over a
				// right child link
				else
				{
					node_pointer	p = node->parent;
					while (p != nullptr && node == p->left)
					{
						node = p;
						p = p->parent;
					}

					node = p;
				}

				return (*this);
			}
		
			// postfix
			map_iterator				operator--( int )
			{
				map_iterator old = *this;
				operator--();
				
				return (old);
			}

		protected:
	
			node_pointer					node;
	
	};

	/*	Bidirectional Iterator const class template
		Bidirectional iterators are iterators that can be used to access the
		sequence of elements in a range in both directions (towards the end
		and towards the beginning).
	*/

	template <	class T,
				class Node,
				class Category = std::bidirectional_iterator_tag,
				class Distance = ptrdiff_t,
				class Pointer = T*,
				class Reference = T& >
	class const_map_iterator
	{

		typedef T											value_type;
		typedef Node*	                                    node_pointer;
		typedef Distance									difference_type;
		typedef const Pointer								pointer;
		typedef const Reference								reference;
		typedef Category									iterator_category;

		public:

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			const_map_iterator( void ) : node(nullptr) { }

			const_map_iterator( node_pointer it ) : node(it) { }

			const_map_iterator( const const_map_iterator &src )
			{
				node = src.node;
			}

			~const_map_iterator( void ) { }

			node_pointer				base( void ) const
			{
				return (node);
			}

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (node->data);
			}

			pointer						operator->( void ) const
			{
				return (&(node->data));
			}

			/* Increment/Decrement												*/
			
			// prefix 
			const_map_iterator				&operator++( void )
			{
				//	Down to the right and left as possible
				if (node->right != nullptr)
					{
						node = node->right;

						while (node->left != nullptr)
							node = node->left;
					}
				// Move up the tree until we have moved over a
				// left child link
				else
				{
					node_pointer p = node->parent;
					while (p != nullptr && node == p->right)
					{
						node = p;
						p = p->parent;
					}

					node = p;
				}

				return (*this);
			}
		
			// postfix
			const_map_iterator				operator++( int )
			{
				const_map_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			const_map_iterator				&operator--( void )
			{
				//	One to the left and downode to right as possible
				if (node->left != nullptr)
				{
					node = node->left;

					while (node->right != nullptr)
						node = node->right;
				}
				// Move up the tree until we have moved over a
				// right child link
				else
				{
					node_pointer p = node->parent;
					while (p != nullptr && node == p->left)
					{
						node = p;
						p = p->parent;
					}

					node = p;
				}

				return (*this);
			}
		
			// postfix
			const_map_iterator			operator--( int )
			{
				const_map_iterator old = *this;
				operator--();
				
				return (old);
			}

		protected:
	
			node_pointer				node;
	
	};

}

#endif