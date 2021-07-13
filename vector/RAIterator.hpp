/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAIterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:45:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/13 13:01:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAITERATOR_HPP
# define RAITERATOR_HPP

#include <iterator>

namespace ft {

	/*	Random Access Iterator class template									*/
	template < typename Iterator >
	class RAIterator
	{
		public:
	
			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			RAIterator( void ) : _p(nullptr) { }

			RAIterator( Iterator *p ) : _p(p) { }
			
			RAIterator( const Iterator *p ) : _p(p) { }

			RAIterator( const RAIterator &src )
			{
				_p = src._p;
			}

			~RAIterator( void ) { }
	
			/*						OPERATORS OVERLOAD							*/

			/* Assignation														*/

			RAIterator			&operator=( const RAIterator &rhs )
			{
				_p = rhs._p;

				return (*this);
			}

			/* Comparison														*/

			bool				operator==( const RAIterator &rhs )
			{
				if (_p == rhs._p)
					return (true);
			
				return (false);
			}

			bool				operator!=( const RAIterator &rhs )
			{
				return !(*this == rhs);
			}

			/* Dereference														*/
			
			Iterator			&operator*( void )
			{
				return (*_p);
			}

			Iterator			*operator->( void )
			{
				return (_p);
			}

			Iterator			operator[]( std::size_t i )
			{
				return(_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			RAIterator			&operator++( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			RAIterator			operator++( int )
			{
				RAIterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			RAIterator&			operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			RAIterator			operator--( int )
			{
				RAIterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			RAIterator			operator+( const int n )
			{
				RAIterator	tmp = *this;
				tmp._p += n;

				return (tmp);
			}

			RAIterator			operator-( const int n )
			{
				RAIterator	tmp = *this;
				tmp._p -= n;

				return (tmp);
			}

			size_t				operator-( RAIterator const *rhs )
			{
				RAIterator	tmp = *this;

				return (tmp._p - rhs->_p);
			}
			
			friend inline Iterator	operator-(const RAIterator &lhs, const RAIterator &rhs)
			{
				return (lhs._p - rhs._p);
			}

			/* Comparison														*/

			bool				operator<( const RAIterator &rhs )
			{
				if (this->_p < rhs._p )
					return (true);
				
				return (false);
			}
			
			bool				operator>( const RAIterator &rhs )
			{
				return (rhs < this);
			}
			
			bool				operator<=( const RAIterator &rhs )
			{
				return !(this > rhs);
			}
			
			bool				operator>=( const RAIterator &rhs )
			{
				return !(this < rhs);
			}

		private:
	
			Iterator						*_p;
	
	};

	/*	Reverse Random Access Iterator class template							*/
	template < class Iterator >
	class rev_RAIterator
	{
		public:

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			rev_RAIterator( void ) : _p(nullptr) { }

			explicit rev_RAIterator( Iterator *p ) : _p(p) { }
			
  			rev_RAIterator ( const rev_RAIterator &rev_it )
			{
				_p = rev_it._p;
			}
	
			Iterator			base( void ) const
			{
				Iterator		ret(_p);

				return (ret);
			}

			/*						OPERATORS OVERLOAD							*/

			// /* Assignation														*/

			// rev_RAIterator		&operator=( const rev_RAIterator &rhs )
			// {
			// 	_p = rhs._p;

			// 	return (*this);
			// }

			/* Comparison														*/

			// bool				operator==( const rev_RAIterator &rhs )
			// {
			// 	if (_p == rhs._p)
			// 		return (true);
			
			// 	return (false);
			// }

			// bool				operator!=( const rev_RAIterator &rhs )
			// {
			// 	return !(this == rhs);
			// }

			/* Dereference														*/
			
			Iterator			&operator*( void )
			{
				Iterator		ret(_p);

				ret--;

				return (*ret);
			}

			Iterator			*operator->( void )
			{
				return (&(operator*()));
			}

			Iterator			operator[]( std::size_t i )
			{
				return(_p[-i-1]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			rev_RAIterator		&operator++( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			rev_RAIterator		operator++( int )
			{
				rev_RAIterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			rev_RAIterator& 	operator--( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			rev_RAIterator 		operator--( int )
			{
				rev_RAIterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			rev_RAIterator		operator+( const int n )
			{
				rev_RAIterator	tmp = *this;
				tmp._p =+ n;

				return (tmp);
			}

			rev_RAIterator		operator-( const int n )
			{
				rev_RAIterator	tmp = *this;
				tmp._p =- n;

				return (tmp);
			}

		private:
	
			Iterator						*_p;
	};
}

#endif