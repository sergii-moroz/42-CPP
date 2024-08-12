#include "HumanA.hpp"
#include "HumanB.hpp"

void	check_leaks( void )
{
	system("leaks violence");
}

int	main(void)
{
	//atexit(check_leaks);
	{
		Weapon	club = Weapon("crude spliked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spliked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
