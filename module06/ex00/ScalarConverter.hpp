/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:40:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 11:26:43 by smoroz           ###   ########.fr       */
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

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class ScalarConverter
{
	public:
		ScalarConverter();
		virtual				~ScalarConverter() = 0;
		static void			convert(std::string);
	private:
		static bool			isChar(std::string);
		static bool			isDouble(std::string);
		static bool			isFloat(std::string);
		static bool			isInteger(std::string);
		static bool			isSpecial(std::string);

		static char			strToChar(std::string const &);
		static double		strToDouble(std::string const &);
		static float		strToFloat(std::string const &);
		static int			strToInteger(std::string const &);

		static void			displayDouble(double);
		static void			displayFloat(float);
		static void			displayInteger(int);
		static void			displayChar(char c);
		static void			displaySpecial(std::string const &);
		static void			displayImpossible(void);

		static std::string	trim(std::string const &);
};

#endif
