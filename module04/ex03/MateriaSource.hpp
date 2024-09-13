/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:25:14 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/11 21:52:52 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &);
		MateriaSource &	operator=(MateriaSource const &);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &);

	private:
		AMateria	*_materials[4];
};

#endif
