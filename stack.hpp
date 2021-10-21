/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:48:49 by fmanetti          #+#    #+#             */
/*   Updated: 2021/10/21 19:10:16 by fmanetti         ###   ########.fr       */
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
		private:

			/*							MEMBER TYPES							*/

			typedef	T											value_type;
			typedef Container									container_type;
			typedef	size_t										size_type;
	
			/*							MEMBER VARIABLES						*/

			container_type										c();

			/*		-*-*-*-*-*-*-*-  MEMBER FUNCTIONS -*-*-*-*-*-*-*-			*/

			/*							CONSTRUCTORS							*/

			explicit stack ( const container_type& ctnr = container_type() ) : c(ctnr)
			{
			}

			bool	empty() const
			{
				return (!c._size);
			}

			size_type size() const
			{
				return (_size);
			}

			value_type& top()
			{
				return (c.begin());
			}

			const value_type& top() const
			{
				return (c.begin());
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}
			
			void pop()
			{
				c.erase(c.end() - 1);
			}
	};

	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

}

#endif