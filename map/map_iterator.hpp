/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:12:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/23 16:49:12 by fmanetti         ###   ########.fr       */
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

	template < typename T >
	class iterator : public ft::iterator_base<std::bidirectional_iterator_tag,T>
	{

		public:

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			iterator( void ) : _p(nullptr) { }

			iterator( T it ) : _p(it) { }

			iterator( const iterator &src )
			{
				_p = src._p;
			}

			~iterator( void ) { }

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (*_p);
			}

			iterator_type				operator->( void ) const
			{
				return (_p);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			iterator					&operator++( void )
			{

				return (*this);
			}
		
			// postfix
			iterator					operator++( int )
			{
				iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			iterator					&operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			iterator					operator--( int )
			{
				iterator old = *this;
				operator--();
				
				return (old);
			}

		protected:
	
			value_type					*n;
	
	};

}

#endif