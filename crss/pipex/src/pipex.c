#include "pipex.h"

int	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char *envp[])
{
	int fd_infile;
	int	fd_outfile;
	pid_t child_cmd1;
	pid_t child_cmd2;

	if (open_files(&fd_infile, &fd_outfile, infile, outfile) == -1)
		return (-2);
	if (access(infile, R_OK) != 0 || access(outfile, W_OK) != 0)
		return (-3);
	if (dup2(fd_infile, 0) == -1)
		return (-4);	
	if (dup2(fd_outfile, 1) == -1)
		return (-5);	
	if (execve(infile, cmd1, envp) == -1)
		return (-6)
	child_cmd1 = fork(void);	
	child_cmd2 = fork(void);	
	if (child_cmd1 == -1 || child_cmd2 == -1)
		return (-7);
	if (waitpid(child_cmd1) == -1 || waitpid(child_cmd2) == -2)
		return (-8);
}

int open_files(int *fd_in, int *fd_out, char *infile, char *outfile)
{
	*fd_in = open(infile, O_RDONLY | O_CREAT);
	*fd_out = open(outfile, O_RDWR | O_CREAT);
	if (*fd_in == -1 || *fd_out == -1)
		return (-1);
	return (0);
}
