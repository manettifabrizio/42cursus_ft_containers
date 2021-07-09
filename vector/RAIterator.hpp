/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAIterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:45:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/09 18:36:03 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAITERATOR_HPP
# define RAITERATOR_HPP

#include <iterator>

namespace ft {

	/*	Random Access Iterator class template									*/
	template < typename T >
	class RAIterator : public std::iterator<
		std::random_access_iterator_tag, T >
	{
		public:
	
			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			RAIterator( void ) : _p(nullptr) { }

			RAIterator( T *p ) : _p(p) { }
			
			RAIterator( const T *p ) : _p(p) { }

			RAIterator( const RAIterator &src )
			{
				_p = src._p;
			}

			~RAIterator( void ) { }
	
			/*						OPERATORS OVERLOAD							*/

			/* Assignation														*/

			RAIterator	&operator=( const RAIterator &rhs )
			{
				_p = rhs._p;

				return (*this);
			}

			/* Comparison														*/

			bool		operator==( const RAIterator &rhs )
			{
				if (_p == rhs._p)
					return (true);
			
				return (false);
			}

			bool		operator!=( const RAIterator &rhs )
			{
				return !(this == rhs);
			}

			/* Dereference														*/
			
			T			&operator*( void )
			{
				return (*_p);
			}

			T			*operator->( void )
			{
				return (_p);
			}

			T			operator[]( std::size_t i )
			{
				return(_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			RAIterator	&operator++( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			RAIterator	operator++( int )
			{
				RAIterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			RAIterator& operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			RAIterator operator--( int )
			{
				RAIterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			RAIterator	operator+( int const n )
			{
				RAIterator	tmp = *this;
				tmp._p =+ n;

				return (tmp);
			}

			RAIterator	operator-( int const n )
			{
				RAIterator	tmp = *this;
				tmp._p =- n;

				return (tmp);
			}

			size_t		operator-( RAIterator const *rhs )
			{
				RAIterator	tmp = *this;

				return (tmp._p - rhs->_p);
			}
			
			/* Comparison														*/

			bool		operator<( const RAIterator &rhs )
			{
				if (this->_p < rhs._p )
					return (true);
				
				return (false);
			}
			
			bool		operator>( const RAIterator &rhs )
			{
				return (rhs < this);
			}
			
			bool		operator<=( const RAIterator &rhs )
			{
				return !(this > rhs);
			}
			
			bool		operator>=( const RAIterator &rhs )
			{
				return !(this < rhs);
			}

		private:
	
			T						*_p;
	
	};
}

#endif