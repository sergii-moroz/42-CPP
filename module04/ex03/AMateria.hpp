/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:21:37 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 10:15:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(AMateria const & copy);
		virtual ~AMateria();

		AMateria &			operator=(AMateria const & ref);
		std::string const &	getType() const;
		void				setType(std::string const & type);
		virtual AMateria	*clone() = 0;
		virtual void		use(ICharacter & target);

	protected:
		std::string	_type;
};

#endif
