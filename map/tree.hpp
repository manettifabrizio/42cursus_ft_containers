/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/13 15:30:09 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include "map_iterator.hpp"
#include "../reverse_iterator.hpp"
#include "utility.hpp"

namespace ft
{

	/*	Struct of one tree node														*/
	template < class T >
	struct							tree_node
	{
		T							data;
		tree_node					*left;
		tree_node					*right;
		tree_node					*parent;
	};

	/*	Binary Search Tree class template
		A binary tree is a hierarchical data structure whose behavior is similar
		to a tree, as it contains root and leaves (a node that has no child).
		The root of a binary tree is the topmost node. Each node can have at
		most two children, which are referred to as the left child and
		the right child.
	*/
	template < class T, class Compare, class Alloc >
	class tree
	{
		public:

			/*							MEMBER TYPES								*/

			typedef T													value_type;
			typedef Compare												value_compare;
			typedef Alloc												allocator_type;
			typedef T&													reference;
			typedef	const T&											const_reference;
			typedef T*													pointer;
			typedef const T*											const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef typename ft::map_iterator<T, tree_node<T> >			iterator;
			typedef typename ft::const_map_iterator<T, tree_node<T> >	const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;


		private:

			typedef tree_node<value_type>								node;
			typedef typename Alloc::template rebind<node>::other		allocator_node;

			/*							MEMBER VARIABLES							*/

			node													*_root;
			// node													*_sentinel_begin;
			// node													*_sentinel_end;
			size_t													_size;
			value_compare											_comp;
			allocator_type											_all;
			allocator_node											_all_node;

			/*							TREE UTILITIES								*/

			node			*newNode( node *par = nullptr,
				const_reference data = value_type() )
			{
				node		*n;

				n = _all_node.allocate(1);

				_all.construct(&(n->data), data);

				n->left = nullptr;
				n->right = nullptr;
				n->parent = par;

				return (n);
			}

			void			delete_node( node *n )
			{
				_all.destroy(&(n->data));
				_all_node.deallocate(n, 1);

				n = nullptr;
			}

			void			copy( node *to, node *from )
			{
				if (!from)
					to = nullptr;
				else
				{
					to = newNode(from->parent, from->data);
					copy(to->left, from->left);
					copy(to->right, from->right);
				}
			}

			void			deleteTree( node *elem )
			{
				if (elem)
				{
					deleteTree(elem->left);
					deleteTree(elem->right);
					delete_node(elem);
				}
			}

			template < typename Key >
			ft::pair<iterator,bool>	check_key( const Key &key )
			{
				iterator it = find(key);

				if (it != end())
					return (ft::make_pair<iterator,bool>(it, false));

				return (ft::make_pair<iterator,bool>(it, true));
			}

			template < typename Key >
			ft::pair<const_iterator,bool>	check_key( const Key &key ) const
			{
				const_iterator it = find(key);

				if (it != end())
					return (ft::make_pair<const_iterator,bool>(it, false));

				return (ft::make_pair<const_iterator,bool>(it, true));
			}
			
			node							*leftMostNode( void ) const
			{
				node		*n = _root;

				if (n)
					while (n->left)
						n = n->left;

				return (n);
			}

			node							*rightMostNode( void ) const
			{
				node		*n = _root;
				if (n)
					while (n->right)
						n = n->right;

				return (n);
			}

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-				*/

			/*							CONSTRUCTORS								*/

			/*	First (Default constructor)
				Empty tree, root is NULL.											*/
			tree( const value_compare& comp = value_compare(),
				const allocator_type& alloc = allocator_type() ) : _root(nullptr),
				_size(0), _comp(comp), _all(alloc)
			{
				// _sentinel_begin = newNode();

				// _sentinel_end = newNode();
			}

			/*	Second (Range constructor)
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range.								*/
			template <class InputIterator>
			tree( InputIterator first, InputIterator last,
				const value_compare& comp = value_compare(),
				const allocator_type& alloc = allocator_type() ) : _root(nullptr),
				_size(last - first), _comp(comp), _all(alloc)
			{

				for (first; first != last; ++first)
					insert((*first)->data);
			}

			/*	Third (Copy constructor)
				Constructs a container with a copy of each of the elements
				in x.																*/
			tree( const tree &x ) : _size(x._size), _comp(x._comp),
				_all(x._all), _all_node(x._all_node)
			{
				copy(_root, x._root);
			}
			
			/*							DESTRUCTOR									*/
			
			~tree( void )
			{
				deleteTree(_root);
			}

			/*						OPERATOR OVERLOAD								*/

			/*	Assignation operator
				Assigns new contents to the container, replacing its current
				content.															*/
			tree							&operator=( const tree &x )
			{
				clear();

				// _sentinel_begin = x._sentinel_begin;
				// _sentinel_end = x._sentinel_end;
				_size = x._size;
				_all = x._all;

				copy(_root, x._root);

				return (*this);
			}

			/*					-|-|-|-|-  ITERATORS -|-|-|-|-						*/

			/*	begin()
				Returns an iterator referring to the first element
				in the tree.														*/
			iterator					begin( void )
			{
				return ( iterator(leftMostNode()) );
			}

			const_iterator				begin( void ) const
			{
				return ( const_iterator(leftMostNode()) );
			}

			/*	end()
				Returns an iterator referring to the past-the-end element
				in the map container.												*/
			iterator					end( void )
			{
				return ( iterator(nullptr) );
			}

			const_iterator				end( void ) const
			{
				return ( const_iterator(nullptr) );
			}
			
			/*	rbegin()
				Returns a reverse iterator pointing to the last element in
				the container (i.e., its reverse beginning).						*/
			reverse_iterator 			rbegin( void )
			{
				return ( reverse_iterator(end()) );
			}

			const_reverse_iterator 		rbegin( void ) const
			{
				return ( const_reverse_iterator(end()) );
			}
			
			/*	rend()
				Returns a reverse iterator pointing to the theoretical element
				right before the first element in the map container
				(which is considered its reverse end).								*/	
			reverse_iterator			rend( void )
			{
				return ( reverse_iterator(begin()) );
			}

			const_reverse_iterator		rend( void ) const
			{
				return ( const_reverse_iterator(begin()) );
			}

			/*					-|-|-|-|-  CAPACITY -|-|-|-|-						*/

			/*	empty()
				Test whether the tree is empty.										*/
			bool				empty( void ) const
			{
				return ( _size == 0 );
			}

			/*	size()
				Return the number of nodes in the tree.								*/
			size_type			size( void ) const
			{
				return ( _size );
			}

			/*	max_size()
				Returns the maximum number of elements that the tree can hold.		*/
			size_type			max_size( void ) const
			{
				return ( _all.max_size() );
			}

			/*					-|-|-|-|-  MODIFIERS -|-|-|-|-						*/

			/*	insert()
				Extends the container by inserting new elements, effectively
				increasing the container size by the number of elements inserted.	*/
			ft::pair<iterator,bool>		insert( const value_type &val )
			{
				
				// Tree root doesn't exist
				if (!_root)
				{
					_root = newNode(nullptr, val);
					return (ft::make_pair<iterator,bool>(iterator(_root), true));
				}

				// Da capire perché const_iterator -> iterator non converte e segfaulta
				ft::pair<iterator, bool>		p = check_key(val.first);

				//	Key found
				if (p.second == false) {
					return (p);
				}

				// Key not found				
				node							*n = _root;
				node							*parent = nullptr;

				// Find last leaf using _comp
				while (n)
				{
					parent = n;
					if (_comp(val, n->data))
						n = n->left;
					else
						n = n->right;
				}

				node							*newnode = newNode(parent, val);

				if (_comp(val, parent->data))
					parent->left = newnode;
				else
					parent->right = newnode;

				_size++;

				return (ft::make_pair<iterator,bool>(iterator(newnode), true));
			}

			iterator					insert( iterator position,
				const value_type& val )
			{
				static_cast<void>(position);

				return (insert(val).first);
			}

			template <class InputIterator>
			void						insert( InputIterator first,
				InputIterator last )
			{
				for (;first != last; ++first)
					insert(*first);
			}

			/*	erase()
				Removes from the map container either a single element or a range
				of elements ([first,last)).											*/
			void						erase( iterator position )
			{
				node		*curr = *position;
				node		*prev = (*position)->parent;

				// Check if the node to be
				// deleted has atmost one child.
				if (curr->left == NULL || curr->right == NULL)
				{
					// newCurr will replace
					// the node to be deleted.
					node* newCurr;

					// if the left child does not exist.
					if (curr->left == NULL)
						newCurr = curr->right;
					else
						newCurr = curr->left;

					// check if the node to
					// be deleted is the root.
					if (prev == NULL)
					{
						delete_node(_root);
						_root = newCurr;
						return ;
					}

					// check if the node to be deleted
					// is prev's left or right child
					// and then replace this with newCurr
					if (curr == prev->left)
						prev->left = newCurr;
					else
						prev->right = newCurr;

					// free memory of the
					// node to be deleted.
					delete_node(curr);
				}
				// node to be deleted has
				// two children.
				else
				{
					node* p = NULL;
					node* tmp;

					// Compute the inorder successor
					tmp = curr->right;
					while (tmp->left != NULL)
					{
						p = tmp;
						tmp = tmp->left;
					}

					// Check if the parent of the inorder
					// successor is the curr or not(i.e. curr=
					// the node which has the same data as
					// the given data by the user to be
					// deleted). If it isn't, then make the
					// the left child of its parent equal to
					// the inorder successor'd right child.
					if (p != NULL)
						p->left = tmp->right;

					// if the inorder successor was the
					// curr (i.e. curr = the node which has the
					// same data as the given data by the
					// user to be deleted), then make the
					// right child of the node to be
					// deleted equal to the right child of
					// the inorder successor.
					else
						curr->right = tmp->right;

					tmp->right = curr->right;
					tmp->left = curr->left;
					tmp->parent = curr->parent;

					delete_node(curr);
				}
			}

			template < typename Key >
			size_type					erase( const Key &k )
			{
				iterator it = find(k);

				if (it != end())
				{
					erase(it);
					return (1);
				}
				
				return (0);
			}

			void						erase( iterator first, iterator last )
			{
				for (; first != last; ++first)
					erase(first);
			}

			/*	swap()
				Exchanges the content of the container by the content of x,
				which is another map of the same type. Sizes may differ.			*/
			void						swap( tree &x )
			{
				tree		tmp(x);

				x = *this;
				*this = tmp;
			}

			/*	clear()
				Removes all elements from the map container (which are destroyed),
				leaving the container with a size of 0.								*/
			void						clear( void )
			{
				for (iterator it = begin(); it != end(); ++it)
					_all.destroy(&((*it)->data));
				
				_size = 0;
			}

			/*					-|-|-|-|-  OPERATIONS -|-|-|-|-						*/

			/*	find()
				Searches the container for an element with a key equivalent to k
				and returns an iterator to it if found, otherwise it returns an
				iterator to map::end.												*/
			template < typename Key >
			iterator					find( const Key &k )
			{
				iterator	it;

				for (it = begin(); it != end(); ++it)
					if (it->first == k)
						return (it);

				// std::cout << "find" << std::endl;

				return (it);
			}

			template < typename Key >
			const_iterator				find( const Key &k ) const
			{
				const_iterator		it;

				for (it = begin(); it != end(); ++it)
					if (it->first == k)
					{
						// std::cout << "const_find key found: " << it->first << " " << it->second << std::endl;
						return (it);
					}

				// std::cout << "const_find" << std::endl;

				return (it);
			}

			/*	count()
				Searches the container for elements with a key equivalent to k
				and returns the number of matches.									*/
			template < typename Key >
			size_type					count ( const Key &k ) const
			{
				iterator it = find(k);

				if (it != end())
					return (1);
				
				return (0);
			}
	};
}

#endif