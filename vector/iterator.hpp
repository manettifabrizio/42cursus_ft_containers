/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:45:51 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/16 16:30:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>

namespace ft {

	/*	Random Access Iterator class template									*/
	template < typename Iter >
	class iterator
	{
		public:
	
			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			iterator( void ) : _p(nullptr) { }

			iterator( Iter *p ) : _p(p) { }
			
			iterator( const iterator *p ) : _p(p) { }

			iterator( const iterator &src )
			{
				_p = src._p;
			}

			~iterator( void ) { }
	
			Iter				*base( void ) const
			{
				return (_p);
			}

			/*						OPERATORS OVERLOAD							*/

			// /* Assignation														*/

			// iterator			&operator=( const iterator &rhs )
			// {
			// 	_p = rhs._p;

			// 	return (*this);
			// }

			/* Comparison														*/

			bool				operator==( const iterator &rhs ) const
			{
				return (_p == rhs._p);
			}

			bool				operator!=( const iterator &rhs ) const
			{
				return !(*this == rhs);
			}

			/* Dereference														*/
			
			Iter			&operator*( void ) const
			{
				return (*_p);
			}

			Iter			*operator->( void ) const
			{
				return (_p);
			}

			Iter			operator[]( std::size_t i )
			{
				return(_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			iterator		&operator++( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			iterator		operator++( int )
			{
				iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			iterator			&operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			iterator			operator--( int )
			{
				iterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			iterator			operator+( const int n )
			{
				iterator	tmp = *this;
				tmp._p += n;

				return (tmp);
			}

			iterator			operator-( const int n )
			{
				iterator	tmp = *this;
				tmp._p -= n;

				return (tmp);
			}

			size_t				operator-( iterator const *rhs )
			{
				iterator	tmp = *this;

				return (tmp._p - rhs->_p);
			}
			
			friend inline size_t	operator-(const iterator &lhs, const iterator &rhs)
			{
				return (lhs._p - rhs._p);
			}

			/* Comparison														*/

			bool				operator<( const iterator &rhs )
			{
				return (this->_p < rhs._p );
			}
			
			bool				operator>( const iterator &rhs )
			{
				return (rhs < this);
			}
			
			bool				operator<=( const iterator &rhs )
			{
				return !(this > rhs);
			}
			
			bool				operator>=( const iterator &rhs )
			{
				return !(this < rhs);
			}

		private:
	
			Iter						*_p;
	
	};

		/*	Random Access Constant Iterator class template									*/
	template < typename Iter >
	class const_iterator : public iterator<Iter>
	{
		public:
	
			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			const_iterator( void ) : _p(nullptr) { }

			const_iterator( Iter *p ) : _p(p) { }
			
			const_iterator( const const_iterator *p ) : _p(p) { }

			const_iterator( const const_iterator &src )
			{
				_p = src._p;
			}

			~const_iterator( void ) { }
	
			Iter				*base( void ) const
			{
				return (_p);
			}

			/*						OPERATORS OVERLOAD							*/

			// /* Assignation														*/

			// const_iterator			&operator=( const const_iterator &rhs )
			// {
			// 	_p = rhs._p;

			// 	return (*this);
			// }

			/* Comparison														*/

			bool				operator==( const const_iterator &rhs ) const
			{
				return (_p == rhs._p);
			}

			bool				operator!=( const const_iterator &rhs ) const
			{
				return !(*this == rhs);
			}

			/* Dereference														*/
			
			Iter			&operator*( void ) const
			{
				return (*_p);
			}

			Iter			*operator->( void ) const
			{
				return (_p);
			}

			Iter			operator[]( std::size_t i )
			{
				return(_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			const_iterator		&operator++( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			const_iterator		operator++( int )
			{
				const_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			const_iterator			&operator--( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			const_iterator			operator--( int )
			{
				const_iterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			const_iterator			operator+( const int n )
			{
				const_iterator	tmp = *this;
				tmp._p += n;

				return (tmp);
			}

			const_iterator			operator-( const int n )
			{
				const_iterator	tmp = *this;
				tmp._p -= n;

				return (tmp);
			}

			size_t				operator-( const_iterator const *rhs )
			{
				const_iterator	tmp = *this;

				return (tmp._p - rhs->_p);
			}
			
			friend inline Iter	operator-(const const_iterator &lhs, const const_iterator &rhs)
			{
				return (lhs._p - rhs._p);
			}

			/* Comparison														*/

			bool				operator<( const const_iterator &rhs )
			{
				return (this->_p < rhs._p );
			}
			
			bool				operator>( const const_iterator &rhs )
			{
				return (rhs < this);
			}
			
			bool				operator<=( const const_iterator &rhs )
			{
				return !(this > rhs);
			}
			
			bool				operator>=( const const_iterator &rhs )
			{
				return !(this < rhs);
			}

			static const bool is_iterator = true;

		private:
	
			Iter						*_p;
	
	};

}

#endif