#include "pipex.h"

void	return_error(int error)
{
	if (error == -1)
		perror("Pipex: infile command1 command2 outfile");
	else if (error == -2)
		perror("open failed");
	else if (error == -3)
		perror("access failed");
	else if (error == -4)
		perror("dup2 failed");
	else if (error == -5)
		perror("execve failed");
	else if (error == -6)
		perror("fork failed");
	else if (error == -7)
		perror("waitpid failed");
	exit(0);
}
