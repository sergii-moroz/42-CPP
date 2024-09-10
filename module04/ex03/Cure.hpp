/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:37:44 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 20:10:53 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : AMateria
{
	public:
		Cure();
		Cure(Cure const &);
		~Cure();
		Cure &	operator=(Cure const &);
		AMateria	*clone();
		void		use(ICharacter & target);
};

#endif
