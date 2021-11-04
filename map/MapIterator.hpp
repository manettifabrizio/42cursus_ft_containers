/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:12:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/11/04 16:39:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include "../iterator_base.hpp"

namespace ft {

	/*	Bidirectional Iterator class template
		Bidirectional iterators are iterators that can be used to access the
		sequence of elements in a range in both directions (towards the end
		and towards the beginning).
	*/

	template <	class T,
				class Node >
	class map_iterator
	{
		public:

			typedef T											value_type;
			typedef Node*										node_pointer;
			typedef ptrdiff_t									difference_type;
			typedef T*											pointer;
			typedef T&											reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			map_iterator( void ) : node(NULL) { }

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

			operator map_iterator<const T, Node>(void) const
			{
				return (map_iterator<const T, Node>(node));
			}

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (*(node->data));
			}

			pointer						operator->( void ) const
			{
				return (node->data);
			}

			/* Increment/Decrement												*/
			

			/*	The increment is always low to high: it always check if there
				is something on the left before going down on the right.		*/

			// prefix 
			map_iterator				&operator++( void )
			{
				//	Down to the right and left as possible
				if (node->right != NULL)
					{
						node = node->right;

						while (node->left != NULL)
							node = node->left;
					}
				// Move up the tree until we have moved over a
				// left child link
				else
				{
					node_pointer p = node->parent;
					while (p != NULL && node == p->right)
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
				if (node->left != NULL)
				{
					node = node->left;

					while (node->right != NULL)
						node = node->right;
				}
				// Move up the tree until we have moved over a
				// right child link
				else
				{
					node_pointer	p = node->parent;
					while (p != NULL && node == p->left)
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

			/*						RELATIONAL OPERATORS						*/

			bool						operator==(const map_iterator &rhs) const
			{
				return (node == rhs.node);
			}

			bool						operator!=(const map_iterator &rhs) const
			{
				return (node != rhs.node);
			}

		protected:
	
			node_pointer					node;
	
	};

}

#endif