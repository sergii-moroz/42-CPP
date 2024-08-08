#include "Zombie.hpp"

int	main(void)
{
	Zombie	sven("Sven");
	sven.announce();

	Zombie	*max = newZombie("Max");
	max->announce();
	delete max;

	randomChump("Bob");

	return (0);
}
