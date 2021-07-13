/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:03:22 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/13 17:19:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <stdexcept>

#include "RAIterator.hpp"

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			/*							MEMBER TYPES							*/

			typedef	T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	ft::RAIterator<T>							iterator;
			typedef const ft::RAIterator<T>						const_iterator;
			typedef ft::rev_RAIterator<T>						reverse_iterator;
			typedef	const ft::rev_RAIterator<T>					const_reverse_iterator;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

		private:

			/*							VARIABLES								*/

			T											*_array;
			size_type									_size;
			size_type									_capacity;
			allocator_type								_all;

			size_type					compute_capacity( void )
			{
				if (_size > max_size() || _capacity == max_size())
					throw std::length_error("Size is greater than size max.");

				_capacity = (_size) ? 1 : 0;

				while (_capacity && _capacity <= _size)
					_capacity *= 2;

				if (_capacity > max_size())
					_capacity = max_size();

				return (_capacity);
			}

			size_type					compute_capacity( size_type n )
			{
				if (n > max_size())
					throw std::length_error("Size is greater than size max.");

				_capacity = (n) ? 1 : 0;

				while (_capacity <= n)
					_capacity *= 2;

				if (_capacity > max_size())
					_capacity = max_size();

				return (_capacity);
			}

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/* First (Default constructor)
				Empty container, no elements									*/
			vector( void ) : _array(NULL), _size(0), _capacity(0),
				_all(allocator_type()) { }

			/* Second
				Constructs a container with n elements. Each element is a
				copy of val.													*/	
			vector( size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type() ) : _size(n),
				_capacity(compute_capacity()), _all(alloc)
			{
				_array = _all.allocate(_capacity);

				for (int i = 0; i < n; i++)
					_array[i] = val;

			}
			
			/* Third
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range, in the same order.			*/
			template <class InputIterator>
			vector( InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type() ) :
				_array(nullptr), _size(0), _capacity(compute_capacity()),
				_all(alloc)
			{
				std::cout	<< "capacity:" << _capacity << std::endl
							<< "size:" << _size << std::endl;

				for (; first != last; first++)
					push_back(*first);

			}
			
			/* Fourth
				Constructs a container with a copy of each of the elements
				in x, in the same order.										*/
			vector( const vector &src ) : _size(src._size),
				_capacity(src._capacty), _all(src._all)
			{
				_array = _all.allocate(_capacity);

				for (int i = 0; i < _size; i++)
					_array[i] = src._array[i];

			}

			/*							DESTRUCTOR								*/

			/*	This destroys all container elements, and deallocates all the
				storage capacity allocated by the vector using its allocator.	*/
			~vector( void )
			{
				_all.deallocate(_array, _size);

				_array = NULL;

			}

			/*						OPERATOR OVERLOAD							*/

			/*	Assign content
				Copies all the elements from x into the container.				*/
			vector				&operator=( const vector &x )
			{
				if (_array)
					_all.deallocate(_array, _size);

				_size = x._size;

				_capacity = x._capacity;

				_array = _all.allocate(_capacity);

				for (int i = 0; i < _size; i++)
					_array[i] = x._array[i];
				
				return ( *this );
			}

			/*	Access element
				Returns a reference to the element at position n in the vector
				container.														*/
			reference					operator[]( size_type n )
			{
				return ( _array[n] );
			}

			const_reference				operator[]( size_type n ) const
			{
				return ( _array[n] );
			}



			/*					-|-|-|-|-  ITERATORS -|-|-|-|-					*/

			/* begin()
				Returns an iterator pointing to the first element in the
				vector.															*/
			iterator					begin( void )
			{
				return ( iterator(&(_array[0])) );
			}

			const_iterator				begin( void ) const
			{
				return ( iterator(&(_array[0])) );
			}

			/* rbegin()
				Returns a reverse iterator pointing to the last element in the
				vector.															*/
			reverse_iterator 			rbegin( void )
			{
				return ( reverse_iterator(&(_array[_size - 1])) );
			}

			const_reverse_iterator 		rbegin( void ) const
			{
				return ( reverse_iterator(&(_array[_size - 1])) );
			}

			/* end()
				Returns an iterator referring to the past-the-end element
				in the vector container. If the container is empty, this
				function returns the same as vector::begin.						*/	
			iterator					end( void )
			{
				if (_size > 0)
					return ( iterator(&(_array[_size])) );
				
				return ( iterator(&(_array[0])) );
			}

			const_iterator				end( void ) const
			{
				if (_size > 0)
					return ( iterator(&(_array[_size])) );
				
				return ( iterator(&(_array[0])) );
			}							

			/* rend()
				Returns a reverse iterator pointing to the theoretical element
				preceding the first element in the vector.						*/	
			reverse_iterator			rend( void )
			{
				return ( reverse_iterator(&(_array[-1])) );
			}

			const_reverse_iterator		rend( void ) const
			{
				return ( reverse_iterator(&(_array[_size])) );
			}

			/*					-|-|-|-|-  CAPACITY -|-|-|-|-					*/
	
			/*	size()
				Returns the number of elements in the vector.					*/
			size_type					size( void ) const
			{
				return ( _size );
			}

			/*	max_size()
				Returns the maximum number of elements that the vector can
				hold. 															*/
			size_type					max_size( void ) const
			{
				return ( _all.max_size() );
			}

			/*	resize()
				Resizes the container so that it contains n elements.			*/
			void						resize( size_type n, value_type val
				= value_type() )
			{
				if (n < _size)
					for (iterator it = end(); _size > n; it--)
						pop_back(it);
				else
					for (iterator it = end(); _size < n; it++)
						push_back(val);

			}

			/*	resize()
				Returns the size of the storage space currently allocated for
				the vector, expressed in terms of elements.						*/
			size_type					capacity( void ) const
			{
				return ( _capacity );
			}

			/*	empty()
				Returns whether the vector is empty.							*/
			bool						empty( void ) const
			{
				if (_size == 0)
					return ( true );
				
				return ( false );
			}

			void						reserve( size_type n )
			{
				if (n > _capacity)
				{
					_capacity = compute_capacity(n);

					// std::cout << "reserve: " << _capacity << std::endl;

					value_type	*a = _all.allocate(_capacity);
				
					for (size_type i = 0; i < _size; i++)
						a[i] = _array[i];

					_all.deallocate(_array, _size);
				
					_array = a;

					// for (iterator it = begin(); it != end(); ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;
				}
			}

			/*				-|-|-|-|-  ELEMENT ACCESS -|-|-|-|-					*/

			/*	at()
				Returns a reference to the element at position n in the vector.	*/
			reference					at( size_type n )
			{
				if (n < 0 || n > (_size - 1))
					throw std::out_of_range("Elem out of range requested");

				return ( _array[n] );
			}

			const_reference				at( size_type n ) const
			{
				if (n < 0 || n > (_size - 1))
					throw std::out_of_range("Elem out of range requested");

				return ( _array[n] );
			}

			/*	front()
				Returns a reference to the first element in the vector.			*/
			reference					front( void )
			{
				return ( _array[0] );
			}

			const_reference				front( void ) const
			{
				return ( _array[0] );
			}

			/*	back()
				Returns a reference to the last element in the vector.			*/
			reference					back( void )
			{
				return ( _array[_size - 1] );
			}

			const_reference				back( void ) const
			{
				return ( _array[_size - 1] );
			}

			/*					-|-|-|-|-  MODIFIERS -|-|-|-|-					*/

			/*	assign()
				Assigns new contents to the vector, replacing its current
				contents, and modifying its size accordingly.					*/
			template <class InputIterator>
  			void						assign( InputIterator first,
				InputIterator last )
			{
				_all.deallocate(_array, sizeof(_array));

				_size = last - first;

				_capacity = compute_capacity();

				_array = _all.allocate(_capacity);

				for (first; first != last; first++)
					push_back(first);
			}

			void						assign ( size_type n,
				const value_type &val )
			{
				_all.deallocate(_array, _size);

				_size = n;

				_capacity = compute_capacity();

				_array = _all.allocate(_capacity);

				for (int i = 0; i < n; i++)
					push_back(val);
			}

			/*	push_back()
				Adds a new element at the end of the vector, after its current
				last element. The content of val is copied (or moved) to the
				new element.													*/
			void						push_back( const value_type& val )
			{
				if ((_size + 1) > _capacity)
				{
					_capacity = compute_capacity(_size + 1);

					value_type	*a = _all.allocate(_capacity);
				
					for (size_type i = 0; i < _size; i++)
						a[i] = _array[i];
					a[_size] = val;

					_all.deallocate(_array, _size);
				
					_array = a;

				}
				else
					_array[_size] = val;
				_size++;
			}

			/*	pop_back()
				Removes the last element in the vector, effectively reducing
				the container size by one.										*/
			void						pop_back( void )
			{
				if (_size > 0)
				{
					_all.destroy(end() - 1);
					_size--;
				}
			}

			/*	insert()
				The vector is extended by inserting new elements before the
				element at the specified position, effectively increasing the
				container size by the number of elements inserted.				*/
			iterator					insert ( iterator position,
				const value_type& val )
			{

				if (position != end())
				{
					reserve(_size + 1);

					iterator it = end();

					for (; it != position; --it)
						*it = *(it - 1);

					*position = val;

					_size++;

					return ( position );
				}
				else
					push_back(val);
				
				return ( end() - 1 );
			}

			/*	Have to use enable_if + is_integer to make compilator to choose second overload */

			void						insert( iterator position,
				int n, const value_type &val )
			{

				std::cout << "One" << std::endl;

				if (position != end() - 1)
				{
					size_type pos = position - begin();

					// std::cout << "before: ";
					// for (iterator it = begin(); it != end(); ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;

					reserve(_size + n);

					position = begin() + pos;

					// std::cout << "after: ";
					// for (iterator it = begin(); it != end() + n; ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;

					// std::cout 	<< "position: " << *position << std::endl
					// 			<< "position + n: " << *(position + n) << std::endl;

					iterator it = position + n;

					for (; it != (end() + n); ++it)
						*it = *(it - n);

					// for (it = begin(); it != end(); ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;
					
					it = position;

					for (; it != (position + n); ++it)
						*it = val;

					_size += n;
				}
				else
					for (int x = 0; x < n; x++)
						push_back(val);
			}
	
			template <class InputIterator>
			void						insert( iterator position,
				InputIterator first, InputIterator last )
			{

				size_type n = last - first;

				if (position != end())
				{
					size_type pos = position - begin();

					// std::cout << "before: ";
					// for (iterator it = begin(); it != end(); ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;

					reserve(_size + n);

					position = begin() + pos;

					// std::cout << "after: ";
					// for (iterator it = begin(); it != end() + n; ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;

					// std::cout 	<< "position: " << *position << std::endl
					// 			<< "position + n: " << *(position + n) << std::endl;

					iterator it = position + n;

					for (; it != (end() + n); ++it)
						*it = *(it - n);

					// for (it = begin(); it != end(); ++it)
					// 	std::cout << *it << ' ';
					// std::cout << std::endl;
					
					it = position;

					for (; it != position + n; ++it)
						*it = *(first++);

					_size += n;
				}
				else
					for (size_type x = 0; x < n; x++)
						push_back(*(first++));
			}
		
			/*	erase()
				Removes from the vector either a single element (position)
				or a range of elements ([first,last)).							*/
			iterator				erase( iterator position )
			{
				_all.destroy(position);
				if (end() - position > 0)
					for (iterator it = position; it != end; ++it)
						*it = *(it + 1);
				_size--;
			}

			iterator				erase( iterator first, iterator last )
			{

			}
	};
};

#endif