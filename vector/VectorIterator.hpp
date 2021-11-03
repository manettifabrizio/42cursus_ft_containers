/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:05:52 by fmanetti          #+#    #+#             */
/*   Updated: 2021/11/02 16:54:26 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "../iterator_base.hpp"
#include "RandomAccessIterator.hpp"

namespace ft {

	template < typename T >
	class iterator : public random_access_iterator<T>
	{

			/*							MEMBER TYPES							*/

		private:

			typedef random_access_iterator<T>				rit;

		public:

			typedef T										value_type;
			typedef ptrdiff_t								difference_type;
			typedef T*										pointer;
			typedef T&										reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			iterator( void ) : rit() { }

			iterator( pointer it ) : rit(it) { }

		private:

			iterator( rit const &src ) : rit(src) { }

		public:
 
			// virtual ~iterator( void ) { }

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (*this->_p);
			}

			pointer						operator->( void ) const
			{
				return (this->_p);
			}

			reference					operator[]( difference_type i ) const
			{
				return (this->_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			iterator					&operator++( void )
			{
				rit::operator++();

				return (*this);
			}
		
			// postfix
			iterator					operator++( int )
			{	
				return (rit::operator++(0));
			}
		
			// prefix
			iterator					&operator--( void )
			{
				rit::operator--();

				return (*this);
			}
		
			// postfix
			iterator					operator--( int )
			{
				return (rit::operator--(0));
			}

			/* Arithmethic														*/

			iterator					operator+( difference_type n ) const
			{
				return (rit::operator+(n));
			}

			// iterator					operator+( const iterator &rhs ) const
			// {
			// 	iterator	tmp = *this;

			// 	tmp._p += rhs._p;

			// 	return (tmp);
			// }

			friend iterator				operator+( difference_type n,
				const iterator &rhs)
			{
				return (rhs.operator+(n));
			};

			iterator					operator-( difference_type n ) const
			{
				return (rit::operator-(n));
			}

			difference_type				operator-( const rit &rhs ) const
			{
				return (rit::operator-(rhs));
			}

			iterator					&operator+=( difference_type n )
			{
				this->_p += n;

				return (*this);
			}

			iterator					&operator-=( difference_type n )
			{
				this->_p -= n;

				return (*this);
			}

	};

		template < typename T >
	class const_iterator : public random_access_iterator<T>
	{

			/*							MEMBER TYPES							*/

		private:

			typedef random_access_iterator<T>				rit;

		public:

			typedef T										value_type;
			typedef ptrdiff_t								difference_type;
			typedef const T*								pointer;
			typedef const T&								reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			const_iterator( void ) : rit() { }

			const_iterator( value_type *it ) : rit(it) { }

			const_iterator( rit const &src ) : rit(src) { }

			// virtual ~const_iterator( void ) { }

			/*						OPERATORS OVERLOAD							*/

			/* Dereference														*/

			reference					operator*( void ) const
			{
				return (*this->_p);
			}

			pointer						operator->( void ) const
			{
				return (this->_p);
			}

			reference					operator[]( difference_type i ) const
			{
				return (this->_p[i]);
			}

			/* Increment/Decrement												*/
			
			// prefix 
			const_iterator				&operator++( void )
			{
				rit::operator++();

				return (*this);
			}
		
			// postfix
			const_iterator				operator++( int )
			{	
				return (rit::operator++(0));
			}
		
			// prefix
			const_iterator				&operator--( void )
			{
				rit::operator--();

				return (*this);
			}
		
			// postfix
			const_iterator				operator--( int )
			{
				return (rit::operator--(0));
			}

			/* Arithmethic														*/

			const_iterator				operator+( difference_type n ) const
			{
				return (rit::operator+(n));
			}

			// const_iterator			operator+( const const_iterator &rhs ) const
			// {
			// 	const_iterator	tmp = *this;

			// 	tmp._p += rhs._p;

			// 	return (tmp);
			// }

			friend const_iterator		operator+( difference_type n,
				const const_iterator &rhs)
			{
				return (rhs.operator+(n));
			};

			const_iterator				operator-( difference_type n ) const
			{
				return (rit::operator-(n));
			}

			difference_type				operator-( const rit &rhs ) const
			{
				return (rit::operator-(rhs));
			}

			const_iterator				&operator+=( difference_type n )
			{
				this->_p += n;

				return (*this);
			}

			const_iterator				&operator-=( difference_type n )
			{
				this->_p -= n;

				return (*this);
			}

	};

}

#endif