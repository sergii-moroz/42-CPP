#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("Zombie-1");
	Zombie	*z2;

	z2 = z1.newZombie("Zombie-42");
	z1.randomChump("Zombie-13");
	z2->~Zombie();
	return (0);
}
