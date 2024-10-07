/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:06:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 10:49:27 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>


# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class Data
{
	public:
		Data(int count, double price, std::string name);
		Data(Data const &);
		~Data();
		Data &		operator=(Data const &);

		std::string	getName(void) const;
		double		getPrice(void) const;
		int			getCount(void) const;
		void		setName(std::string name);
		void		setPrice(double price);
		void		setCount(int count);

	private:
		Data();
		int			_count;
		double		_price;
		std::string	_name;
};

std::ostream &	operator<<(std::ostream &, Data const &);

#endif
