/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:05:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/21 17:41:09 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "../iterator_base.hpp"

namespace ft {

	/*	Random Access Iterator class template
		Random-access iterators are iterators that can be used to access
		elements at an arbitrary offset position relative to the element
		they point to, offering the same functionality as pointers.
	*/

	template < typename Iter >
	class iterator
	{

			/*							MEMBER TYPES							*/

		private:

			typedef iterator_traits<Iter>						it_traits;

		public:

			typedef Iter										iterator_type;
			typedef typename it_traits::iterator_category		iterator_category;
			typedef typename it_traits::value_type				value_type;
			typedef typename it_traits::difference_type			difference_type;
			typedef typename it_traits::pointer					pointer;
			typedef typename it_traits::reference				reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			iterator( void ) : _p(nullptr) { }

			iterator( Iter it ) : _p(it) { }

			iterator( const iterator &src )
			{
				_p = src._p;
			}

			~iterator( void ) { }
	
			iterator_type				base( void ) const
			{
				return (_p);
			}

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

			reference					operator[]( difference_type i ) const
			{
				return (_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			iterator					&operator++( void )
			{
				++_p;

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

			/* Arithmethic														*/

			iterator					operator+( difference_type n ) const
			{
				iterator	tmp = *this;

				tmp._p += n;

				return (tmp);
			}

			iterator					&operator+=( difference_type n )
			{
				_p += n;

				return (*this);
			}

			iterator					operator-( difference_type n ) const
			{
				iterator	tmp = *this;
				tmp._p -= n;

				return (tmp);
			}

			iterator					&operator-=( difference_type n )
			{
				_p -= n;

				return (*this);
			}

		protected:
	
			iterator_type				_p;
	
	};

}

#endif