/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:12:11 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 19:29:00 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {

	/*	Bidirectional Iterator class template
		Bidirectional iterators are iterators that can be used to access the
		sequence of elements in a range in both directions (towards the end
		and towards the beginning).
	*/

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