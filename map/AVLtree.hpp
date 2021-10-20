/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/20 19:05:15 by fmanetti         ###   ########.fr       */
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
		T							*data;
		tree_node					*left;
		tree_node					*right;
		tree_node					*parent;
	};

	/*	AVL Tree class template
		A binary tree is a hierarchical data structure whose behavior is similar
		to a tree, as it contains root and leaves (a node that has no child).
		The root of a binary tree is the topmost node. Each node can have at
		most two children, which are referred to as the left child and
		the right child.
	*/
	template < class T, class Compare, class Alloc >
	class AVLtree
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
			typedef typename Alloc::template rebind<value_type>::other	allocator_data;

			/*							MEMBER VARIABLES							*/

			node													*_root;
			size_t													_size;
			value_compare											_comp;
			allocator_type											_all;
			allocator_node											_all_node;
			allocator_data											_all_data;

			/*							TREE UTILITIES								*/

			node			*newNode( node *par = nullptr,
				const_reference data = value_type() )
			{
				node		*n;

				n = _all_node.allocate(1);
				n->data = _all_data.allocate(1);

				_all.construct(n->data, data);

				n->left = nullptr;
				n->right = nullptr;
				n->parent = par;

				return (n);
			}

			void			delete_node( node *n )
			{
				_all.destroy(n->data);
				_all_data.deallocate(n->data, 1);
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

			void			delete_tree( node *elem )
			{
				if (elem)
				{
					delete_tree(elem->left);
					delete_tree(elem->right);
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

			// node							*leftMostNode( void ) const
			// {
			// 	node		*n = _root;

			// 	if (n)
			// 		while (n->left)
			// 			n = n->left;

			// 	return (n);
			// }

			node							*leftMostNode( node *n ) const
			{
				if (n)
					while (n->left)
						n = n->left;

				return (n);
			}

			node							*rightMostNode( node *n ) const
			{
				if (n)
					while (n->right)
						n = n->right;

				return (n);
			}

			node							*rotateLeft( node *n )
			{
				node	*tmp;				//	A(n) -> B -> C
				
				tmp = n->right;				//	tmp = B
				tmp->parent = n->parent;
				n->right = tmp->left;		//	A->right = B->left
				n->parent = tmp;
				tmp->left = n;				//	B->left = A;

				return (tmp);				//	Granparent = B
			}


			/*			X					X
					  	 \					 \
				   		  C		=>			  B
						 / \				   \
						B	A					C
			*/
			node							*rotateRight( node *n )
			{
				node	*tmp;				//	C(n) -> B(tmp) -> A
				
				tmp = n->left;				//	tmp = B;
				tmp->parent = n->parent;	//	B->parent = C->parent
				n->left = tmp->right;		//	C->left = B->right
				n->parent = tmp;			 
				tmp->right = n;				//	B->right = C;

				return (tmp);				//	Granparent = B
			}

			node							*rotateLeftRight( node *n )
			{
				n->left = rotateLeft(n->left);
				
				return (rotateRight(n));
			}

			node							*rotateRightLeft( node *n )
			{
				n->right = rotateRight(n->right);

				return (rotateLeft(n));
			}

			int								heigth( node *n )
			{
				if (!n)
					return (0);
				else
        			return (ft::max(heigth(n->left), heigth(n->right)) + 1);
			}

			void							rebalance( node *n )
			{
				//	Unbalanced on the left
				if (heigth(n->left) - heigth(n->right) > 1)
				{
					// Unbalanced on left child
					if (heigth(n->left->left) > heigth(n->left->right))
						n = rotateRight(n);
					// Unbalanced on right child
					else
						n = rotateLeftRight(n);
				}
				//	Unbalanced on the right
				else
				{
					// Unbalanced on left child
					if (heigth(n->right->left) < heigth(n->right->right))
						n = rotateLeft(n);
					// Unbalanced on right child
					else
						n = rotateRightLeft(n);
				}

				// Node n was the root
				if (!(n->parent))
					_root = n;
			} 

			void							check_balance( node *n )
			{
				if (heigth(n->left) - heigth(n->right) > 1 ||
					heigth(n->left) - heigth(n->right) < -1)
					rebalance(n);
				if (!(n->parent))
					return ;
				check_balance(n->parent);
			}

			void							add( node *par, node *n )
			{
				if (_comp(*(par->data), *(n->data)))
				{
					if (!(par->right))
					{
						par->right = n;
						n->parent = par;
						_size++;
					}
					else
						add(par->right, n);
				}
				else
				{
					if (!par->left)
					{
						par->left = n;
						n->parent = par;
						_size++;
					}
					else
						add(par->left, n);
				}
				check_balance(n);
			}

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-				*/

			/*							CONSTRUCTORS								*/

			/*	First (Default constructor)
				Empty tree, root is NULL.											*/
			AVLtree( const value_compare& comp = value_compare(),
				const allocator_type& alloc = allocator_type() ) : _root(nullptr),
				_size(0), _comp(comp), _all(alloc)
			{
			}

			/*	Second (Range constructor)
				Constructs a container with as many elements as the range
				[first,last), with each element constructed from its
				corresponding element in that range.								*/
			template <class InputIterator>
			AVLtree( InputIterator first, InputIterator last,
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
			AVLtree( const AVLtree &x ) : _size(x._size), _comp(x._comp),
				_all(x._all), _all_node(x._all_node)
			{
				copy(_root, x._root);
			}
			
			/*							DESTRUCTOR									*/
			
			~AVLtree( void )
			{
				delete_tree(_root);
			}

			/*						OPERATOR OVERLOAD								*/

			/*	Assignation operator
				Assigns new contents to the container, replacing its current
				content.															*/
			AVLtree							&operator=( const AVLtree &x )
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
				return ( iterator(leftMostNode(_root)) );
			}

			const_iterator				begin( void ) const
			{
				return ( const_iterator(leftMostNode(_root)) );
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
					_size++;
					return (ft::make_pair<iterator,bool>(iterator(_root), true));
				}

				// Da capire perché const_iterator -> iterator non converte e segfaulta
				ft::pair<iterator, bool>		p = check_key(val.first);

				//	Key found
				if (p.second == false)
					return (p);

				//	Key not found, create new node
				node							*newnode = newNode(nullptr, val);

				add(_root, newnode);

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

  			// value_type		*copy_pair(value_type p)
			// {
			// 	value_type *par = _all.allocator(1);
			// 	*par = value_type(p.first, p.second);

    		// 	return ( par );
  			// }

			/*	erase()
				Removes from the map container either a single element or a range
				of elements ([first,last)).											*/
			void						erase( iterator position )
			{
				node		*curr = position.base();
				node		*prev = position.base()->parent;

				// No children case
				if (curr->left == nullptr && curr->right == nullptr)
				{
					if (prev->right == curr)
						prev->right = nullptr;
					else if (prev->left == curr)
						prev->left = nullptr;
					delete_node(curr);
				}
				// One child case
				else if (curr->left == nullptr || curr->right == nullptr)
				{
					// Delete the root
					if (!prev)
					{
						delete_node(_root);
						if (curr->right)
							_root = curr->right;
						else
							_root = curr->left;
						// position.base() = _root;
						return ;
					}
					else if (prev->right == curr)
					{
						if (curr->right)
							prev->right = curr->right;
						else
							prev->right = curr->left;
						delete_node(curr);
						prev->right->parent = prev;
					}
					else
					{
						if (curr->right)
							prev->left = curr->right;
						else
							prev->left = curr->left;
						delete_node(curr);
						prev->left->parent = prev;
					}
				}
				// Two childs case
				else
				{
					// Root case to do
					if (!prev)
					{
						curr = rightMostNode(curr->left);
						_root->data = curr->data;
						curr->data = nullptr;
						erase(iterator(curr));		// Check why if I delete this line it segfault
					}
					else if (prev && prev->left == curr)
					{
						prev->left = curr->left;
						prev->left->right = curr->right;
						delete_node(curr);
						prev->left->parent = prev;
						prev->left->right->parent = prev->left;
					}
					else if (prev && prev->right == curr)
					{
						prev->right = curr->left;
						prev->right->right = curr->right;
						delete_node(curr);
						prev->right->parent = prev;
						prev->right->right->parent = prev->right;
					}
				}

				check_balance(begin().base());
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
				iterator	tmp;

				while (first != last)
				{
					tmp = first++;
					erase(tmp);
				}
			}

			/*	swap()
				Exchanges the content of the container by the content of x,
				which is another map of the same type. Sizes may differ.			*/
			void						swap( AVLtree &x )
			{
				AVLtree		tmp(x);

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