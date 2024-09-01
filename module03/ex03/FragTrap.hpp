/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:18:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:18:41 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Frag_TRAP_HPP
# define Frag_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap( FragTrap const & );
		FragTrap( std::string const & );
		FragTrap & operator=( FragTrap const & );
		~FragTrap();

		void		highFivesGuys();
};

std::ostream & operator<<(std::ostream & out, FragTrap const & ft);

#endif
