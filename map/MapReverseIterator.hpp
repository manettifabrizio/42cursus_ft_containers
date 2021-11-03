/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapReverseIterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:26:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/27 20:32:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPREVERSEITERATOR_HPP
# define MAPREVERSEITERATOR_HPP

#include "../iterator_base.hpp"

namespace ft {

	/*	Reverse Iterator class template
		This class reverses the direction in which a bidirectional or
		random-access iterator iterates through a range.
	*/

	template < class Iter >
	class map_reverse_iterator : public Iter
	{

			/*							MEMBER TYPES							*/

		public:

			typedef Iter									iterator_type;
			typedef typename Iter::value_type				value_type;
			typedef typename Iter::node_pointer				node_pointer;
			typedef typename Iter::difference_type			difference_type;
			typedef typename Iter::pointer					pointer;
			typedef typename Iter::reference				reference;
			typedef typename Iter::iterator_category		iterator_category;

			/*					CONSTRUCTORS AND DESTRUCTOR						*/

			map_reverse_iterator( void ) : Iter() { }

			explicit map_reverse_iterator( Iter it ) : _p(it)
			{
			}
			
			template <class It>
			map_reverse_iterator ( const map_reverse_iterator<It> &rev_it ) : _p(rev_it.base())
			{
			}

			iterator_type				base( void ) const
			{
				return (_p);
			}

			/*						OPERATORS OVERLOAD							*/

			/* Assignation														*/

			map_reverse_iterator			&operator=( const map_reverse_iterator &rhs )
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
			map_reverse_iterator			&operator++( void )
			{
				--_p;

				return (*this);
			}
		
			// postfix
			map_reverse_iterator			operator++( int )
			{
				map_reverse_iterator old = *this;
				operator++();
				
				return (old);
			}
		
			// prefix
			map_reverse_iterator			&operator--( void )
			{
				++_p;

				return (*this);
			}
		
			// postfix
			map_reverse_iterator 			operator--( int )
			{
				map_reverse_iterator old = *this;
				operator--();
				
				return (old);
			}

			/* Arithmethic														*/

			map_reverse_iterator			operator+( const int n )
			{
				map_reverse_iterator	tmp = *this;

				tmp._p -= n;

				return (tmp);
			}

			map_reverse_iterator			&operator+=( difference_type n )
			{
				_p -= n;

				return (*this);
			}

			map_reverse_iterator			operator-( const int n )
			{
				map_reverse_iterator	tmp = *this;

				tmp._p += n;

				return (tmp);
			}

			map_reverse_iterator			&operator-=( difference_type n )
			{
				_p += n;

				return (*this);
			}

			protected:

				iterator_type		_p;

	};
}


#endif