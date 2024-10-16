/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:45:58 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/16 09:45:58 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>
# include <iostream>

# define BLACK		"\033[1;30m"
// # define RED		"\033[1;31m"
// # define GREEN		"\033[1;32m"
// # define YELLOW		"\033[1;33m"
// # define BLUE		"\033[1;34m"
// # define MAGENTA	"\033[1;35m"
// # define CYAN		"\033[1;36m"
// # define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &);
		~MutantStack();

		MutantStack &	operator=(MutantStack const &);

	private:
};

# include "MutantStack.tpp"

#endif
