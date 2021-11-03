/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:52:40 by fmanetti          #+#    #+#             */
/*   Updated: 2021/11/02 17:08:32 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

namespace ft {

	/*	Random Access Iterator class template
		Random-access iterators are iterators that can be used to access
		elements at an arbitrary offset position relative to the element
		they point to, offering the same functionality as pointers.
	*/

	template < typename T >
	class random_access_iterator
	{

			/*							MEMBER TYPES							*/

		public:

			typedef T										value_type;
			typedef ptrdiff_t								difference_type;
			typedef T*										pointer;
			typedef T&										reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			random_access_iterator( void ) : _p(NULL) { }

			random_access_iterator( pointer it ) : _p(it) { }

			random_access_iterator( random_access_iterator const &src ) : _p(src._p) { }

			virtual ~random_access_iterator( void ) { }

			random_access_iterator 					&operator=(const
				random_access_iterator &rhs) {
				
				if (this == &rhs)
					return (*this);
				
				_p = rhs._p;

				return (*this);
			}

			/*						OPERATORS OVERLOAD							*/

			/* Increment/Decrement												*/
			
			// prefix 
			random_access_iterator					&operator++( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			random_access_iterator					operator++( int )
			{
				random_access_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			random_access_iterator					&operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			random_access_iterator					operator--( int )
			{
				random_access_iterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			random_access_iterator			operator+( difference_type n ) const
			{
				random_access_iterator	tmp = *this;

				tmp._p += n;

				return (tmp);
			}

			friend random_access_iterator	operator+( difference_type n,
				const random_access_iterator &rhs)
			{
				return (rhs.operator+(n));
			};

			random_access_iterator			operator-( difference_type n ) const
			{
				random_access_iterator	tmp = *this;
				tmp._p -= n;

				return (tmp);
			}

			difference_type					operator-( const
				random_access_iterator &rhs ) const
			{
				random_access_iterator	tmp = *this;

				return (tmp._p - rhs._p);
			}

			/*						RELATIONAL OPERATORS						*/

			bool			operator==( const random_access_iterator &rhs ) const
			{
				return (_p == rhs._p);
			}

			bool			operator!=( const random_access_iterator &rhs ) const
			{
				return (_p != rhs._p);
			}

			bool			operator<( const random_access_iterator &rhs ) const
			{
				return ( _p < rhs._p );
			}
			
			bool			operator>( const random_access_iterator &rhs ) const
			{
				return ( _p > rhs._p );
			}
			
			bool			operator<=( const random_access_iterator &rhs ) const
			{
				return !( _p > rhs._p );
			}
			
			bool			operator>=( const random_access_iterator &rhs ) const
			{
				return !( _p < rhs._p );
			}

		protected:
	
			pointer				_p;
	
	};
}

#endif