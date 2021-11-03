/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorReverseIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:29:25 by fmanetti          #+#    #+#             */
/*   Updated: 2021/11/02 17:26:28 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORREVERSEITERATOR_HPP
# define VECTORREVERSEITERATOR_HPP

#include "../iterator_base.hpp"

namespace ft {

	/*	Reverse Iterator class template
		This class reverses the direction in which a bidirectional or
		random-access iterator iterates through a range.
	*/

	template < class Iter >
	class reverse_iterator
	{

			/*							MEMBER TYPES							*/

		public:

			typedef Iter										iterator_type;
			typedef typename Iter::value_type					value_type;
			typedef typename Iter::difference_type				difference_type;
			typedef typename Iter::pointer						pointer;
			typedef typename Iter::reference					reference;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			reverse_iterator( void ) : _p() { }

			explicit reverse_iterator( iterator_type it ) : _p(it)
			{
			}
			
			template <class It>
			reverse_iterator ( const reverse_iterator<It> &rev_it ) : _p(rev_it.base())
			{
			}

			iterator_type				base( void ) const
			{
				return (_p);
			}

			/*						OPERATORS OVERLOAD							*/

			/* Assignation														*/

			reverse_iterator			&operator=( const reverse_iterator &rhs )
			{
				if (this != &rhs)
					_p = rhs.base();

				return (*this);
			}

			/* Dereference														*/
			
			reference					operator*( void ) const
			{
				Iter		ret(_p);

				--ret;

				return (ret.operator*());
			}

			pointer						operator->( void ) const
			{
				return (&(operator*()));
			}

			reference					operator[]( difference_type i )
			{
				return (*operator+(i));
			}

			/* Increment/Decrement												*/
			
			// prefix 
			reverse_iterator			&operator++( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			reverse_iterator			operator++( int )
			{
				reverse_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			reverse_iterator			&operator--( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			reverse_iterator 			operator--( int )
			{
				reverse_iterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			reverse_iterator			operator+( const int n ) const
			{
				reverse_iterator	tmp = *this;

				tmp._p -= n;

				return (tmp);
			}

			friend reverse_iterator		operator+( difference_type n,
				const reverse_iterator &rhs )
			{
				return (rhs.operator+(n));
			};

			reverse_iterator			&operator+=( difference_type n )
			{
				_p -= n;

				return (*this);
			}

			reverse_iterator			operator-( difference_type n )
			{
				reverse_iterator	tmp = *this;

				tmp._p += n;

				return (tmp);
			}

			template < class It >
			difference_type				operator-( const reverse_iterator<It> &rhs ) const
			{
				return (rhs.base().operator-(_p));
			}


			reverse_iterator			&operator-=( difference_type n )
			{
				_p += n;

				return (*this);
			}

			/*						RELATIONAL OPERATORS						*/

			template < class It >
			bool			operator==(const reverse_iterator<It> &rhs) const
			{
				return (_p.operator==(rhs.base()));
			}

			template < class It >
			bool			operator!=(const reverse_iterator<It> &rhs) const
			{
				return (_p.operator!=(rhs.base()));
			}

			template < class It >
			bool			operator<( const reverse_iterator<It> &rhs ) const
			{
				return (_p.operator>(rhs.base()));
			}
			
			template < class It >
			bool			operator>( const reverse_iterator<It> &rhs ) const
			{
				return (_p.operator<(rhs.base()));
			}
			
			template < class It >
			bool			operator<=( const reverse_iterator<It> &rhs ) const
			{
				return (_p.operator>=(rhs.base()));
			}
			
			template < class It >
			bool			operator>=( const reverse_iterator<It> &rhs ) const
			{
				return (_p.operator<=(rhs.base()));
			}

			protected:

				iterator_type		_p;

	};
}

#endif