#include "get_next_line.h"

int	check_newline(char *c)
{
	if (*c == '\n')
		return (1);
	return (0);
}
