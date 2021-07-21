/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:29:25 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/20 15:48:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RAITERATOR_HPP
# define REV_RAITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft {

	/*	Reverse Iterator class template
		This class reverses the direction in which a bidirectional or
		random-access iterator iterates through a range.
	*/

	template < class Iter >
	class reverse_iterator : public iterator<typename Iter::iterator_type>
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

			reverse_iterator( void ) : Iter() { }

			explicit reverse_iterator( Iter it ) : _p(it)
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
				_p = rhs.base();

				return (*this);
			}

			/* Dereference														*/
			
			reference					operator*( void ) const
			{
				Iter		ret(_p);

				--ret;

				return (*ret);
			}

			pointer						operator->( void ) const
			{
				return (&(operator*()));
			}

			reference					operator[]( difference_type i ) const
			{
				*this += i;

				return (*this);
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

			reverse_iterator			operator+( const int n )
			{
				reverse_iterator	tmp = *this;

				tmp._p -= n;

				return (tmp);
			}

			reverse_iterator			&operator+=( difference_type n )
			{
				_p -= n;

				return (*this);
			}

			reverse_iterator			operator-( const int n )
			{
				reverse_iterator	tmp = *this;

				tmp._p += n;

				return (tmp);
			}

			reverse_iterator			&operator-=( difference_type n )
			{
				_p += n;

				return (*this);
			}

			protected:

				iterator_type		_p;

	};
}

#endif