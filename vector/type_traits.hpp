/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:41:58 by fmanetti          #+#    #+#             */
/*   Updated: 2021/07/15 16:52:39 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {

	/*	enable if
		The type T is enabled as member type enable_if::type if Cond is true.
	*/
	template <bool, typename T = void> struct enable_if {};

	template <typename T> struct enable_if<true, T> { typedef T type; };

	/*	is_integral
		Trait class that identifies whether T is an integral type. Normally,
		in <type_traits> header, it should inherit from integer_constant a
		template designed to provide compile-time constants as types.
		Since we can only use C++98 and the template uses constexpr keyword,
		that is exclusively C++11, I had to adapt the class. This definition
		is uses template specialization to choose the case.						*/

	// Case in wich T is not an int
	template <class T> struct is_integral
	{ static const bool value = false; };

	// Each different int type represent a case
	template <> struct is_integral<bool>				{ static const bool value = true; };
	template <> struct is_integral<char>				{ static const bool value = true; };
	template <> struct is_integral<signed char>			{ static const bool value = true; };
	template <> struct is_integral<unsigned char>		{ static const bool value = true; };
	template <> struct is_integral<wchar_t>				{ static const bool value = true; };
	template <> struct is_integral<short>				{ static const bool value = true; };
	template <> struct is_integral<unsigned short>		{ static const bool value = true; };
	template <> struct is_integral<int>					{ static const bool value = true; };
	template <> struct is_integral<unsigned int>		{ static const bool value = true; };
	template <> struct is_integral<long>				{ static const bool value = true; };
	template <> struct is_integral<unsigned long>		{ static const bool value = true; };
	template <> struct is_integral<long long>			{ static const bool value = true; };
	template <> struct is_integral<unsigned long long>  { static const bool value = true; };

}

#endif