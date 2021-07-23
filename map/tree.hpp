/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/23 17:05:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include "map_iterator.hpp"
#include "utility.hpp"

/*	Struct of one tree node														*/
struct				s_tree
{
	int				data;
	s_tree			*left;
	s_tree			*right;
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

		typedef T											value_type;
		typedef Compare										value_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef ft::iterator<T>								iterator;
		// typedef ft::const_iterator<T>						const_iterator;

	private:

		/*							MEMBER VARIABLES							*/

		s_tree												*_root;
		size_t												_size;
		size_t												_heigth;
		allocator_type										_all;

		/*							TREE UTILITIES								*/

			tree_node					*newNode( value_type data )
			{
				tree_node		*n;

				n = _all.allocate(1);

				_all.construct(&(n->data), data);

				n->left = nullptr;
				n->right = nullptr;

				return (n);
			}

			bool						check_key( const value_type &val )
			{
					if (node.left != nullptr)
						visitNode(node.left);
					if (node.right != nullptr)
						visitNode(node.right);
					if (node.left == nullptr && node.right == nullptr)
					
			}
		

	public:

		/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-				*/

		/*							CONSTRUCTORS								*/

		/*	First (Default constructor)
			Empty tree, root is NULL.											*/
		tree( const allocator_type& alloc = allocator_type() ) :
			_root(nullptr), _size(0), _heigth(0), _all(alloc)
		{
		};

		/*	Third (Copy constructor)
			Constructs a container with a copy of each of the elements
			in x.																*/
		tree( const tree &x )
		{
		}
		
		/*							DESTRUCTOR									*/
		
		~tree( void )
		{
			deleteTree();
			printf("");
		}

		/*						OPERATOR OVERLOAD								*/

		tree							&operator=( const map &x )
		{
			if (this != )	
		}

		value_type						

		/*					-|-|-|-|-  ITERATORS -|-|-|-|-						*/

		/*	begin()
			Returns an iterator referring to the first element
			in the tree.														*/
		iterator			begin( void )
		{
			return ( iterator(_root) );
		}

		// const_iterator		begin();

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

		ft::pair<iterator,bool>				insert ( const value_type &val )
		{
			s_tree		*n = _root;

			check_key(val.first);

			while (1)
				if (!n)
				{
					n = newNode(data);
					break ;
				}
				else if (value_compare(val, n->data))
					n = n->left;
				else
					n = n->right;
			
			return (n);
		}

		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last);

		/*					-|-|-|-|-  OBSERVERS -|-|-|-|-						*/

		key_compare key_comp() const;
		value_compare value_comp() const;

		/*					-|-|-|-|-  OPERATIONS -|-|-|-|-						*/

		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;

		size_type count (const key_type& k) const;

		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;

		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>				equal_range (const key_type& k);

		allocator_type get_allocator() const;

		s_tree			*newNode( int data )
		{
			s_tree		*n = new s_tree();

			n->data = data;
			n->left = nullptr;
			n->right = nullptr;

			return (n); 
		}

		void			insert(s_tree **root, int data)
		{
			if (!(*root))
				(*root) = newNode(data);
			else if (data <= (*root)->data)
				insert(&((*root)->left), data);
			else
				insert(&((*root)->right), data);
			_size++;
		}

		s_tree			*find(s_tree *root, int data)
		{
			if (!root)
				return (NULL);
			else if (root->data == data)
				return (root);
			else if (data <= root->data)
				return (find(root->left, data));
			else
				return (find(root->right, data));
		}

};

#endif