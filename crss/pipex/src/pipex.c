#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	int		fd_infile;
	int		fd_outfile;
	pid_t child_cmd;
	pid_t parent_cmd;

	if (open_files(&fd_infile, &fd_outfile, args[0], args[3]) == -1)
		return (-2);
	if (access(args[0], R_OK) != 0 || access(args[3], W_OK) != 0)
		return (-3);
	if (dup2(fd_infile, 0) == -1)
		return (-4);	
	if (dup2(fd_outfile, 1) == -1)
		return (-5);	
	if (execve(args[0], &args[1], envp) == -1 ||
			execve(args[2], &args[3], envp) == -1)
		return (-6);
	child_cmd = fork();	
	parent_cmd = fork();	
	if (child_cmd == -1 || parent_cmd == -1)
		return (-7);
	if (waitpid(child_cmd, NULL, 0) == -1 ||
			waitpid(parent_cmd, NULL, 0) == -1)
		return (-8);
	return (0);
}

int open_files(int *fd_in, int *fd_out, char *infile, char *outfile)
{
	*fd_in = open(infile, O_RDONLY | O_CREAT);
	*fd_out = open(outfile, O_RDWR | O_CREAT, 0644);
	if (*fd_in == -1 || *fd_out == -1)
		return (-1);
	return (0);
}
