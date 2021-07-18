/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:29:25 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/18 02:35:48 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RAITERATOR_HPP
# define REV_RAITERATOR_HPP

namespace ft {

	/*	Reverse Random Access Iter class template							*/
	template < class Iter >
	class reverse_iterator
	{
		public:

		/*					CONSTRUCTORS AND DESTRUCTOR						*/

		reverse_iterator( void ) : _p(nullptr) { }

		explicit reverse_iterator( Iter *p ) : _p(p) { }
		
		reverse_iterator ( const reverse_iterator &rev_it )
		{
			_p = rev_it._p;
		}

		Iter				base( void ) const
		{
			Iter			ret(_p);

			return (ret);
		}

		/*						OPERATORS OVERLOAD							*/

		// /* Assignation														*/

		// reverse_iterator		&operator=( const reverse_iterator &rhs )
		// {
		// 	_p = rhs._p;

		// 	return (*this);
		// }

		/* Comparison														*/

		bool				operator==( const reverse_iterator &rhs )
		{
			if (_p == rhs._p)
				return (true);
		
			return (false);
		}

		bool				operator!=( const reverse_iterator &rhs )
		{
			return !(*this == rhs);
		}

		/* Dereference														*/
		

		// Still have to understand better in the man says previous elem
		Iter			&operator*( void )
		{
			// Iter		*ret = _p;

			// --ret;

			// return (*ret);
			return (*_p);
		}

		Iter			*operator->( void )
		{
			return (&(operator*()));
		}

		Iter			operator[]( std::size_t i )
		{
			return(_p[-i-1]);
		}

		/* Increment/Decrement												*/
		
		// prefix 
		reverse_iterator		&operator++( void )
		{
			--_p;

			return (*this);
		}
	
		// postfix
		reverse_iterator		operator++( int )
		{
			reverse_iterator old = *this;
			operator++();
			
			return (old);
		}
	
		// prefix
		reverse_iterator& 	operator--( void )
		{
			++_p;

			return (*this);
		}
	
		// postfix
		reverse_iterator 		operator--( int )
		{
			reverse_iterator old = *this;
			operator--();
			
			return (old);
		}

		/* Arithmethic														*/

		reverse_iterator		operator+( const int n )
		{
			reverse_iterator	tmp = *this;
			tmp._p =+ n;

			return (tmp);
		}

		reverse_iterator		operator-( const int n )
		{
			reverse_iterator	tmp = *this;
			tmp._p =- n;

			return (tmp);
		}

	private:

		Iter						*_p;
	};
}

#endif