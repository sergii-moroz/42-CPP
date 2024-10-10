/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:43:22 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 09:16:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"
# define HR			"====================="

template <typename T>
class Array
{
	public:
		// Constructors
		Array() : _array(new T[0])
		{
			std::cout << BLACK << "Array: Default constructor called" << RESET << std::endl;
		}

		Array(unsigned int n) : _array(new T[n])
		{
			std::cout << BLACK << "Array: Consturctor with specified size ( " << n << " ) is called" << std::endl;
		}

		Array(Array const &);

		// Destructor
		~Array()
		{
			std::cout << BLACK << "Array: Destructor called" << std::endl;
			delete [] _array;
		}

		Array &			operator=(Array const &);
		unsigned int &	operator[](unsigned int const &);
		unsigned int &	size(void);

		class IndexOutOfRange : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		T	*_array;
};

#endif
