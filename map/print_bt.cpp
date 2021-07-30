/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bt.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:44:09 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/28 17:59:17 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <__tree>

struct s_tree
{
	int						data;
	struct s_tree			*left;
	struct s_tree			*right;
};

template < class T >
void printmap( T m, std::string s )
{
	std::cout << s << std::endl;

	for (typename T::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << ' ' << it->second
					<< std::endl;
}

int				main()
{
	std::pair<char,int>						p;
	std::map<char, int>						mymap;
	std::map<char, int>::reverse_iterator	rrit;
	std::vector<int>::reverse_iterator		rit;

	mymap.insert ( std::pair<char,int>('a',100) );
  	mymap.insert ( std::pair<char,int>('z',200) );

	printmap( mymap, "mymap" );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	//	Insert II
	std::map<char,int>::iterator it = mymap.begin();
  	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	printmap( mymap, "mymap" );

	return (0);
}