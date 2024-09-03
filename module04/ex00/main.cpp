/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/03 18:02:04 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int	main( void )
{
	// Animal constructors
	Animal	a;
	Animal	b(a);
	Animal	c("some type");
	return (0);
}
