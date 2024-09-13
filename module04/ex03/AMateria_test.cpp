/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:07:30 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/12 20:30:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

int	main(void)
{
	//  Default constructor
	Ice	ice = Ice();
	Ice	ice2 = ice;
	ice = ice2;
	// Destrutor
	// delete ice;
	// delete ice2;

	return (0);
}
