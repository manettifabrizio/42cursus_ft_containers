/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:06:42 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/28 00:06:44 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <map>
#include <memory>

#include "map/AVL.hpp"

namespace ft
{
	/*	Map class template
		Maps are associative containers that store elements formed by a
		combination of a key value and a mapped value, following a
		specific order.
	*/

	template <	class Key,												// map::key_type
				class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
			>
	class map
	{

		public:

			/*							MEMBER TYPES							*/

			typedef Key															key_type;
			typedef	T															mapped_type;
			typedef ft::pair<const Key,T>										value_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef	ft::map_iterator<value_type, tree_node<value_type> >		iterator;
			typedef ft::const_map_iterator<value_type, tree_node<value_type> >	const_iterator;
			typedef ft::map_reverse_iterator<iterator>							reverse_iterator;
			typedef	const ft::map_reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef	ptrdiff_t													difference_type;
			typedef	size_t														size_type;

		private:

			/*	Nested function class value_compare()
				Returns a comparison object that can be used to compare two
				elements to get whether the key of the first one goes
				before the second.												*/
			class value_compare
			{
				private:

					key_compare					_comp;

				public:

					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;

					value_compare (Compare c) : _comp(c)
					{
					}

					bool operator()(const value_type& x, const value_type& y) const
					{
						return (_comp(x.first, y.first));
					}
			};

			typedef ft::AVLtree<value_type, value_compare, Alloc>		base_tree;

			/*							MEMBER VARIABLES						*/

			base_tree											_t;
			key_compare											_key_comp;
			value_compare										_val_comp;
			allocator_type										_all;
			
		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/*	First (Default constructor)
				Empty container, no elements.									*/
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_t(value_compare(comp)), _key_comp(comp),
				_val_comp(value_compare(_key_comp)), _all(alloc)
			{
			}

			/*	Second (Range constructor)
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range.							*/
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
				_t(first, last, value_compare(comp)), _key_comp(comp),
				_val_comp(value_compare(_key_comp)), _all(alloc)
			{
			}

			/*	Third (Copy constructor)
				Constructs a container with a copy of each of the elements
				in x.															*/
			map (const map &x) : _t(base_tree(x._t)), _key_comp(x._key_comp),
				_val_comp(value_compare(_key_comp)), _all(x._all)
			{
			}

			/*							DESTRUCTOR								*/
			
			~map ( void )
			{
			}

			/*						OPERATOR OVERLOAD							*/

			map							&operator=( const map &x )
			{
				_t = x._t;

				return (*this);
			}

			/*	Access element
				If k matches the key of an element in the container, the function
				returns a reference to its mapped value. If k does not match the
				key of any element in the container, the function inserts a new
				element with that key and returns a reference to its mapped value.	*/
			mapped_type					&operator[]( const key_type &k )
			{
				return ((*((_t.insert(ft::make_pair(k,mapped_type()))).first)).second);
			}

			/*					-|-|-|-|-  ITERATORS -|-|-|-|-					*/

			/*	begin()
				Returns an iterator referring to the first element
				in the container.													*/
			iterator					begin( void )
			{
				return (_t.begin());
			}

			const_iterator				begin( void ) const
			{
				return (_t.begin());
			}

			/*	rbegin()
				Returns a reverse iterator pointing to the last element in
				the container (i.e., its reverse beginning).						*/
			reverse_iterator 			rbegin( void )
			{
				return ( _t.rbegin() );
			}

			const_reverse_iterator 		rbegin( void ) const
			{
				return ( _t.rbegin() );
			}

			/*	end()
				Returns an iterator referring to the past-the-end element
				in the map container.											*/
			iterator					end( void )
			{
				return (_t.end());
			}

			const_iterator				end( void ) const
			{
				return (_t.end());
			}
			
			/*	rend()
				Returns a reverse iterator pointing to the theoretical element
				right before the first element in the map container
				(which is considered its reverse end).								*/	
			reverse_iterator			rend( void )
			{
				return ( _t.rend() );
			}

			const_reverse_iterator		rend( void ) const
			{
				return ( _t.rend() );
			}

			/*					-|-|-|-|-  CAPACITY -|-|-|-|-						*/

			/*	empty()
				Test whether the container is empty.								*/
			bool						empty( void ) const
			{
				return ( _t.empty() );
			}

			/*	size()
				Return the number of nodes in the container.						*/
			size_type					size( void ) const
			{
				return ( _t.size() );
			}

			/*	max_size()
				Returns the maximum number of elements that the container
				can hold.															*/
			size_type					max_size( void ) const
			{
				return ( _t.max_size() );
			}

			/*					-|-|-|-|-  MODIFIERS -|-|-|-|-						*/

			/*	insert()
			Extends the container by inserting new elements, effectively
			increasing the container size by the number of elements inserted.		*/
			ft::pair<iterator,bool>		insert( const value_type &val )
			{
				return ( _t.insert(val) );
			}

			iterator					insert( iterator position,
				const value_type& val )
			{
				return ( _t.insert(position, val) );
			}

			template <class InputIterator>
			void						insert( InputIterator first,
				InputIterator last )
			{
				return ( _t.insert(first, last) );
			}

			/*	erase()
				Removes from the map container either a single element or a range
				of elements ([first,last)).											*/
			void						erase( iterator position )
			{
				return ( _t.erase(position) );
			}

			size_type					erase( const key_type &k )
			{
				return ( _t.erase(k) );
			}

			void						erase( iterator first, iterator last )
			{
				return ( _t.erase(first, last) );
			}

			/*	swap()
				Exchanges the content of the container by the content of x,
				which is another map of the same type. Sizes may differ.			*/
			void						swap( map &x )
			{
				return ( _t.swap(x._t) );
			}

			/*	clear()
				Removes all elements from the map container (which are destroyed),
				leaving the container with a size of 0.								*/
			void						clear( void )
			{
				return ( _t.clear() );
			}

			/*					-|-|-|-|-  OBSERVERS -|-|-|-|-					*/

			/*	key_comp()
				Returns a copy of the comparison object used by the container to
				compare keys.														*/
			key_compare					key_comp( void ) const
			{
				return (_key_comp);
			}

			value_compare				value_comp( void ) const
			{
				return (_val_comp);
			}

			/*					-|-|-|-|-  OPERATIONS -|-|-|-|-						*/

			/*	find()
				Searches the container for an element with a key equivalent to k
				and returns an iterator to it if found, otherwise it returns an
				iterator to map::end.												*/
			iterator					find( const key_type &k )
			{
				return ( _t.find(k) );
			}

			const_iterator				find( const key_type &k ) const
			{
				return ( _t.find(k) );
			}

			/*	count()
				Searches the container for elements with a key equivalent to k
				and returns the number of matches.									*/
			size_type					count ( const key_type &k ) const
			{
				return ( _t.count(k) );
			}

			/*	lower_bound()
				Returns an iterator pointing to the first element in the container
				whose key is not considered to go before k (i.e., either it is
				equivalent or goes after).											*/
			iterator					lower_bound( const key_type &k )
			{
				iterator it;

				for (it = begin(); it != end(); ++it)
					if (!_key_comp(it->first, k))
						return (it);
				
				return (it);
			}

			const_iterator				lower_bound( const key_type &k ) const
			{
				const_iterator it;

				for (it = begin(); it != end(); ++it)
					if (!_key_comp(it->first, k))
						return (it);
				
				return (it);
			}

			/*	upper_bound()
				Returns an iterator pointing to the first element in the container
				whose key is considered to go after k.								*/
			iterator					upper_bound( const key_type &k )
			{
				iterator it;

				for (it = begin(); it != end(); ++it)
					if (!_key_comp(it->first, k) && it->first != k)
						return (it);
				
				return (it);
			}

			const_iterator				upper_bound( const key_type &k ) const
			{
				const_iterator it;

				for (it = begin(); it != end(); ++it)
					if (!_key_comp(it->first, k) && it->first != k)
						return (it);
				
				return (it);
			}

			/*	equal_range()
				Returns the bounds of a range that includes all the elements in
				the container which have a key equivalent to k.						*/
			ft::pair<iterator,iterator>	equal_range( const key_type &k )
			{
				iterator it = lower_bound(k);

				iterator it1 = upper_bound(k);
			
				return (ft::make_pair<iterator,iterator>(it, it1));
			}

			ft::pair<const_iterator,const_iterator>	equal_range( const key_type &k ) const
			{
				const_iterator it = lower_bound(k);

				iterator it1 = upper_bound();
			
				return (ft::make_pair<const_iterator,const_iterator>(it, it1));
			}

			/*					-|-|-|-|-  ALLOCATOR -|-|-|-|-						*/

			allocator_type				get_allocator( void ) const
			{
				return (_all);
			}

	};
}

#endif