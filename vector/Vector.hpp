/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:15:16 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/09 18:49:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <list>

#include "RAIterator.hpp"

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{
		private:

			/*							MEMBER TYPES							*/

			typedef	T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	ft::RAIterator<T>								iterator;
			typedef const ft::RAIterator<T>							const_iterator;
			// typedef 											reverse_iterator;
			// typedef											onst_reverse_iterator;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

			/*							VARIABLES								*/

			T											*_array;
			size_type									_size;
			size_type									_capacity;
			allocator_type								_all;

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/* First (Default constructor)
				Empty container, no elements									*/
			Vector( void ) : _array(NULL), _size(0) { }

			/* Second
				Constructs a container with n elements. Each element is a
				copy of val.													*/	
			Vector( size_type n, const value_type& val = value_type() ) : _size(n)
			{
				_array = _all(_size);

				for (int i = 0; i < n; i++)
					_array[i] = val;

			}
			
			/* Third
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range, in the same order.			*/
			template <class InputIterator>
			 Vector( InputIterator first, InputIterator last )
			{}
			
			/* Fourth
				Constructs a container with a copy of each of the elements
				in x, in the same order.										*/
			Vector( const Vector &src )
			{

				_size = src._size;

				_array = _all(_size);
				

				for (int i = 0; i < _size; i++)
					_array[i] = src._array[i];

			}

			/*							DESTRUCTOR								*/

			/*	This destroys all container elements, and deallocates all the
				storage capacity allocated by the vector using its allocator.	*/
			~Vector( void )
			{
				std::allocator<T>		a;

				_all.deallocate(_array, _size);

				_array = NULL;

			}

			/*						OPERATOR OVERLOAD							*/

			/*	Copies all the elements from x into the container.				*/
			Vector				&operator=( const Vector &x )
			{
				_size = x._size;

				_array = _all.allocate(_size);

				for (int i = 0; i < _size; i++)
					_array[i] = x._array[i];
				
				return (*this);
			}

			/*					-|-|-|-|-  ITERATORS -|-|-|-|-					*/

			/* begin()
				Returns an iterator pointing to the first element in the
				vector.															*/
			iterator			begin( void )
			{
				return ( iterator(&(_array[0])));
			}

			const_iterator		begin( void ) const
			{
				return ( &(_array[0]) );
			}

			/* end()
				Returns an iterator referring to the past-the-end element
				in the vector container.										*/												

	};
};

#endif