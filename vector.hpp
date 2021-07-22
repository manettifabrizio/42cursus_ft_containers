/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:03:22 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/21 17:44:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <stdexcept>
#include <type_traits>

#include "vector/vector_iterator.hpp"
#include "vector/vector_reverse_iterator.hpp"
#include "vector/type_traits.hpp"

namespace ft
{
	/*	Vector class template
		Vectors are sequence containers representing arrays that can
		change in size.
	*/

	template <	class T,								// vector::value_type
				class Alloc = std::allocator<T>			// vector::allocator_type
			>
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
			typedef	ft::iterator<pointer>						iterator;
			typedef ft::iterator<const_pointer>					const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

		private:

			/*							MEMBER VARIABLES						*/

			T													*_array;
			size_type											_size;
			size_type											_capacity;
			allocator_type										_all;

			/*							UTILITIES								*/

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

				while (_capacity < n)
					_capacity *= 2;

				if (_capacity > max_size())
					_capacity = max_size();

				return (_capacity);
			}

			void						destroy_array( void )
			{

				if (_array)
				{
					// std::cout << "_size:" << _size << std::endl;

					for (iterator it = begin(); it != end(); ++it)
						_all.destroy(it.base());
					_all.deallocate(_array, _capacity);

					_array = nullptr;
				}
			}

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/* First (Default constructor)
				Empty container, no elements									*/
			vector( const allocator_type& alloc = allocator_type() ) :
				_array(nullptr), _size(0), _capacity(0), _all(alloc)
			{
				// std::cout << "First constructor" << std::endl;
			}

			/* Second (Fill constructor)
				Constructs a container with n elements. Each element is a
				copy of val.													*/	
			vector( size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type() ) : _size(n),
				_capacity(compute_capacity()), _all(alloc)
			{
				// std::cout << "Constructor II: " << n << std::endl;

				_array = _all.allocate(_capacity);

				for (size_type i = 0; i < n; i++)
					_all.construct(&(_array[i]), val);

			}
			
			/* Third (Range constructor)
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range, in the same order.			*/
			template <class InputIterator>
			vector( InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0 ) :
				_size(last - first), _capacity(compute_capacity()), _all(alloc)
			{
				_array = _all.allocate(_capacity);

				size_t	i = 0;

				for (; first != last; first++)
					_all.construct(&(_array[i++]), *first);

			}
			
			/* Fourth (Copy constructor)
				Constructs a container with a copy of each of the elements
				in x, in the same order.										*/
			vector( const vector &src ) : _size(src._size),
				_capacity(src._capacity), _all(src._all)
			{
				_array = _all.allocate(_capacity);

				for (size_type i = 0; i < _size; i++)
					_all.construct(&(_array[i]), src._array[i]);

			}

			/*							DESTRUCTOR								*/

			/*	This destroys all container elements, and deallocates all the
				storage capacity allocated by the vector using its allocator.	*/
			~vector( void )
			{
				// std::cout << "Destructor" << std::endl;
				destroy_array();
			}

			/*						OPERATOR OVERLOAD							*/

			/*	Assign content
				Copies all the elements from x into the container.				*/
			vector				&operator=( const vector &x )
			{
				destroy_array();

				_size = x._size;

				_capacity = x._capacity;

				_array = _all.allocate(_capacity);

				for (size_type i = 0; i < _size; i++)
					_all.construct(&(_array[i]), x._array[i]);
				
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
				return ( const_iterator(&(_array[0])) );
			}

			/* rbegin()
				Returns a reverse iterator pointing to the last element in the
				vector.															*/
			reverse_iterator 			rbegin( void )
			{
				return ( reverse_iterator(end()) );
			}

			const_reverse_iterator 		rbegin( void ) const
			{
				return ( reverse_iterator(end()) );
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
					return ( const_iterator(&(_array[_size])) );
				
				return ( const_iterator(&(_array[0])) );
			}							

			/* rend()
				Returns a reverse iterator pointing to the theoretical element
				preceding the first element in the vector.						*/	
			reverse_iterator			rend( void )
			{
				return ( reverse_iterator(begin()) );
			}

			const_reverse_iterator		rend( void ) const
			{
				return ( reverse_iterator(begin()) );
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
						pop_back();
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
				if (n > max_size())
					throw std::length_error("Size is greater than size max.");

				if (n > _capacity)
				{
					value_type	*a = _all.allocate(n);

					for (size_type i = 0; i < _size; i++)
						_all.construct(&(a[i]), _array[i]);

					destroy_array();
				
					_capacity = n;

					_array = a;

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
				InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0 )
			{
				if (_size > 0)
				{
					size_t	size = last - first;

					// std::cout << "size:" << size << std::endl;

					if (size > _capacity)
						reserve(size);

					clear();
				}

				for (; first != last; first++)
					push_back(*first);
			}

			void						assign ( size_type n,
				const value_type &val )
			{
				// std::cout << "Assign II" << std::endl;

				destroy_array();

				_size = 0;

				_capacity = 0;

				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			/*	push_back()
				Adds a new element at the end of the vector, after its current
				last element. The content of val is copied (or moved) to the
				new element.													*/
			void						push_back( const value_type& val )
			{
				// std::cout << "push_back: " << _size << std::endl;

				if ((_size + 1) > _capacity)
				{

					_capacity = compute_capacity(_size + 1);

					value_type	*a = _all.allocate(_capacity);

					for (size_type i = 0; i < _size; i++)
						_all.construct(&(a[i]), _array[i]);

					destroy_array();

					_array = a;

					_all.construct(&(_array[_size]), val);
				}
				else
					_all.construct(&(_array[_size]), val);
				_size++;
			}

			/*	pop_back()
				Removes the last element in the vector, effectively reducing
				the container size by one.										*/
			void						pop_back( void )
			{
				if (_size > 0)
				{
					iterator	it = end() - 1;

					_all.destroy(it.base());
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
					// std::cout << "ciao << std::endl;
					reserve(_size + 1);

					iterator it = end();

					for (; it != position; --it)
						_all.construct(it.base(), *(it - 1));

					_all.construct(position.base(), val);

					_size++;

					return ( position );
				}
				else
					push_back(val);
				
				return ( end() - 1 );
			}

			void						insert( iterator position,
				size_type n, const value_type &val )
			{
				if (position != end())
				{
					size_type pos = position - begin();

					reserve(_size + n);

					position = begin() + pos;

					// std::cout << "position:" << *position << std::endl;

					iterator it = end() + (n - 1);

					for (; it - n != begin() - 1; --it)
						_all.construct(it.base(), *(it - n)); 
					
					it = position;

					for (; it != position + n; ++it)
						_all.construct(it.base(), val);

					_size += n;
				}
				else
					for (size_type x = 0; x < n; x++)
						push_back(val);
			}
	
			template < class InputIterator >
			void						insert( iterator position,
				InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0 )
			{

				size_type n = last - first;

				if (position != end())
				{
					size_type pos = position - begin();

					reserve(_size + n);

					position = begin() + pos;

					iterator it = end() + (n - 1);

					for (; it - n != begin() - 1; --it)
						_all.construct(it.base(), *(it - n)); 
					
					it = position;

					for (; it != position + n; ++it)
						_all.construct(it.base(), *(first++));

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
				size_type	pos = position - begin();

				_all.destroy(position.base());

				_size--;

				for (iterator it = position; it != end(); ++it)
					*it = *(it + 1);

				return (begin() + pos);
			}

			iterator				erase( iterator first, iterator last )
			{
				size_type	pos = first - begin();

				size_type	n = last - first;

				_size -= (last - first);

				for (iterator it = first; it != last; ++it)
					_all.destroy(it.base());

				for (iterator it = first; it != end(); ++it)
					*it = *(it + n);

				return (begin() + pos);
			}

			/*	swap()
				Exchanges the content of the container by the content of x,
				which is another vector object of the same type.
				Sizes may differ.												*/
			void					swap( vector &x )
			{
				vector		tmp(x);

				x = *this;
				*this = tmp;

			}

			/*	erase()
				Removes all elements from the vector (which are destroyed),
				leaving the container with a size of 0.							*/
			void					clear( void )
			{
				for (iterator it = begin(); it != end(); ++it)
					_all.destroy(it.base());

				_size = 0;
			}
			
			/*	get_allocator()
				Returns a copy of the allocator object associated with
				the vector.														*/
			allocator_type			get_allocator( void ) const
			{
				return (_all);
			}

	};

	/*			-*-*-*-*-*-*-*-  NON-MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

	/*	swap()
		The contents of container x are exchanged with those of y.
		Both container objects must be of the same type
		(same template parameters), although sizes may differ.					*/
	template <class T, class Alloc>
	void					swap( vector<T,Alloc> &x, vector<T,Alloc> &y )
	{
		vector<T, Alloc>		tmp(x);

		x = y;
		y = tmp;
	}

	/*			-|-|-|-|- ALGORYTHMS FOR RELATIONAL OPERATORS -|-|-|-|-			*/

	template <class InputIterator1, class InputIterator2>
	bool 					equal ( InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}

		return (true);
	}

	template <class InputIterator1, class InputIterator2>
  	bool					lexicographical_compare( InputIterator1 first1,
		InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		
		return (first2 != last2);
	}

	/*				-|-|-|-|- RELATIONAL OPERATORS -|-|-|-|-					*/

	template <class T, class Alloc>
	bool operator==( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs )
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		
		return (false);
	}

	template <class T, class Alloc>
	bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

};

#endif