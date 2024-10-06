/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:40:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/02 20:19:54 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <stdlib.h>
# include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		virtual				~ScalarConverter() = 0;
		static void			convert(std::string);
	private:
		static bool			isDouble(std::string);
		static bool			isInteger(std::string);
		static std::string	trim(std::string const &);
		static std::string	trimf(std::string const &);
		static void			displayFromDouble(std::string const &);
		static void			displayFromInteger(std::string const &);
		static void			displayDefault(std::string const &);
		static std::string	displayChar(int c);
		static std::string	displayInt(std::string);
};

#endif
