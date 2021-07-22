/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:44:09 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/22 19:33:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"

#include <map>
#include <__tree>

struct s_tree
{
	int						data;
	struct s_tree			*left;
	struct s_tree			*right;
};

void printBT(const std::string& prefix, const s_tree* node, bool isLeft)
{
	if( node != nullptr )
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}

void printBT(const s_tree* node)
{
	printBT("", node, false);    
}

// int				main()
// {
// 	std::map<int, int>		a;
// 	s_tree					*node = &(a[0]);

// 	printBT(node);

// 	return (0);
// }