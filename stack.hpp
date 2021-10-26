/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:48:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/26 17:54:39 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			/*							MEMBER TYPES							*/

			typedef	T											value_type;
			typedef Container									container_type;
			typedef	size_t										size_type;
	
		protected:

			/*							MEMBER VARIABLES						*/

			container_type										c;

		public:

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			/*	First (Default constructor)
				Constructs a stack container adaptor object.					*/
			explicit			stack ( const container_type& ctnr =
				container_type()) : c(ctnr)
			{
			}

			/*	empty()
				Returns whether the stack is empty: i.e. whether its size
				is zero.														*/
			bool				empty() const
			{
				return (!c.size());
			}

			/*	size()
				Returns the number of elements in the stack.					*/
			size_type			size() const
			{
				return (c.size());
			}

			/*	top()
				Returns a reference to the top element in the stack.			*/
			value_type			&top()
			{
				return (c.back());
			}

			const value_type	&top() const
			{
				return (c.back());
			}

			/*	size()
				Inserts a new element at the top of the stack, above its
				current top element. The content of this new element is
				initialized to a copy of val.									*/
			void				push(const value_type& val)
			{
				c.push_back(val);
			}
			
			/*	size()
				Removes the element on top of the stack, effectively reducing
				its size by one.												*/
			void				pop()
			{
				c.pop_back();
			}

		/*				-|-|-|-|- RELATIONAL OPERATORS -|-|-|-|-					*/

		private:

			friend bool operator== (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{
				return (operator==(lhs.c, rhs.c));
			}
			
			friend bool operator<  (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{
				return (operator<(lhs.c, rhs.c));
			}
	};

	template <class T, class Container>
	bool operator!= (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
	{
		return (!operator==(lhs, rhs));
	}
	
	template <class T, class Container>
	bool operator<= (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
	{
		return (operator==(lhs, rhs) || operator<(lhs, rhs));
	}
	
	template <class T, class Container>
	bool operator>  (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
	{
		return (!operator==(lhs, rhs) && !operator<(lhs, rhs));
	}
	
	template <class T, class Container>
	bool operator>= (const stack<T, Container> & lhs, const stack<T, Container> & rhs)
	{
		return (operator==(lhs, rhs) || operator>(lhs, rhs));
	}

}

#endif