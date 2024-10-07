/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:06:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 10:16:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	public:
		Data(int count, double price, std::string name);
		Data(Data const &);
		~Data();
		Data &		operator=(Data const &);

		std::string	getName(void);
		double		getPrice(void);
		int			getCount(void);
		void		setName(std::string name);
		void		setPrice(double price);
		void		setCount(int count);

	private:
		Data();
		int			_count;
		double		_price;
		std::string	_name;
};

#endif
