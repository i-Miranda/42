#include "Zombie.hpp"

int	main(int argc, char *argv[]) {
	int	n;

	(void)argc;
	n = argv[1];
	Zombie *horde = zombieHorde(n, argv[2]);	

	for (int i = 0; i < n; i++) {
		delete horde[i];
	}
	return (0);
}
