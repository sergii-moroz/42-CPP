/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:43:22 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 15:02:16 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"
# define HR			"====================="

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << BLACK << "Array: Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << BLACK << "Array: Consturctor with specified size ( " << n << " ) is called" << RESET << std::endl;
	// for (unsigned int i=0; i<n; i++)
	// 	memset(_array, 0, sizeof(T));
}

template <typename T>
Array<T>::Array(Array const & copy) : _size(copy.size())
{
	std::cout << BLACK << "Array: Copy constructor called" << RESET << std::endl;
	_array = nullptr;
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << BLACK << "Array: Destructor called" << RESET << std::endl;
	delete [] _array;
}

template <typename T>
Array<T> &			Array<T>::operator=(Array const & rhs)
{
	std::cout << BLACK << "Array: Assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		// if array isn't empty -> free content
		if (_array != nullptr)
			delete [] _array;

		_size = rhs.size();
		_array = new T[_size];

		for (unsigned int i=0; i<_size; i++)
			_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
T &	Array<T>::operator[](unsigned int const & i)
{
	if (i >= size() || _array == nullptr)
		throw Array<T>::IndexOutOfRange();
	else
		return (_array[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
void	Array<T>::_debug(void)
{
	std::cout << MAGENTA << "array field: " << YELLOW << _array << RESET << std::endl;
	std::cout << MAGENTA << "size: " << YELLOW << size() << RESET << std::endl;
	std::cout << MAGENTA << "items: " << RESET << std::endl;
	for (unsigned int i=0; i<size(); i++)
		std::cout << BLACK << "[" << RESET << i << BLACK
			<< "] val:" YELLOW << _array[i] << BLACK << ", address: " << CYAN
			<< &_array[i] << RESET << std::endl;
}

template <typename T>
const char *Array<T>::IndexOutOfRange::what() const throw()
{
	return ("ERROR: Index out of range");
}

#endif
