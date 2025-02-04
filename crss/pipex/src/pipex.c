#include "pipex.h"

int	pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	int fd_infile;
	int	fd_outfile;
	pid_t child_cmd1;
	pid_t child_cmd2;

	if (access(infile, R_OK) != 0 || access(outfile, W_OK) != 0)
		return (-1);
	fd_infile = open((const char *)infile, O_RDONLY | O_CREAT);
	fd_outfile = open((const char *)outfile, O_RDWR | O_CREAT);
	if (dup2(fd_infile, fd_outfile) == -1)
		return (-2);	
	if (execve(infile, (char *const)cmd1, /* char *const envp[]) == -1 */)
		return (-3)
	child_cmd1 = fork(void);	
	child_cmd2 = fork(void);	
	if (child_cmd1 == -1 || child_cmd2 == -1)
		return (-4);
}
