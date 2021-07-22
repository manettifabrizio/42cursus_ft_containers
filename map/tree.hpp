/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:34 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/21 19:12:34 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include <iostream>

struct s_tree
{
	int				data;
	s_tree			*left;
	s_tree			*right;	
};

class tree
{
	public:

		tree( void ) : _root(nullptr) {};
		tree( tree const &src );
		virtual	~tree( void );

		// tree				&operator=( tree const &rhs );

		// int						getValue( void ) const;

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
		}

	private:

		s_tree			*_root;

};

#endif