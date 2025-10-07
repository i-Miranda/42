#include <cstdlib>

#include "Zombie.hpp"

int	main(int argc, char *argv[]) {
	int	n;

	if (argc <= 1)
		return (1);

	n = std::atoi(argv[1]); 
	if (n == 0)
		return (1);

	Zombie *horde = zombieHorde(n, argv[2]);	
	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	return (0);
}
