#include "test.h"

int	main(int argc, char *argv[])
{
	if (argc == 1 || argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strncmp(argv[2], "norminette", 5))
			system("cd ../libft; norminette");
		if (argc == 1 || ft_strncmp(argv[1], "1", 5))
			test_part_one();
		if (argc == 1 || ft_strncmp(argv[1], "2", 5)) 
			test_part_two();
		if (argc == 1 || ft_strncmp(argv[1], "bonus", 5))
			test_bonus();
	}
	return (0);
}
