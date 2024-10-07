/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:02:04 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 17:02:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIER_HPP

# include <stdlib.h>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(Serializer const &);
		Serializer & 		operator=(Serializer const &);

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t *raw);
};

#endif
