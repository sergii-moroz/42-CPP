/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:35:52 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 14:59:57 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : AMateria
{
	public:
		Ice();
		Ice(Ice const &);
		~Ice();
		AMateria	*clone();
		void		use(ICharacter & target);
};

#endif
