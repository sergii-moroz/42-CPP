#include "Zombie.hpp"

void	check_leaks(void)
{
	system("leaks zombieHorde");
}

int	main(void)
{
	// atexit(check_leaks);
	Zombie	*horde = zombieHorde(10, "Bob");
	for (int i=0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
