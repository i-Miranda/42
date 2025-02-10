#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	int		fildes[2];
	int		fd_infile;
	int		fd_outfile;
	pid_t	child_pid;
	pid_t	parent_pid;

	if (pipe(fildes) == -1)
		return (-2);
	if (open_files(&fd_infile, &fd_outfile, args[0], args[3]) == -1)
		return (-3);
	parent_pid = fork();	
	child_pid = fork();	
	if (parent_pid == -1 || child_pid == -1)
		return (-4);
	if (parent_pid == 0)
		run_parent_process(fildes, fd_infile, args, envp);
	if (child_pid == 0)
		run_child_process(fildes, fd_outfile, args, envp);
	if (access(args[0], R_OK) != 0 || access(args[3], W_OK) != 0)
		return (-5);	
	if (waitpid(child_pid, NULL, 0) == -1 ||
			waitpid(parent_pid, NULL, 0) == -1)
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

int	run_parent_process(int fildes[2], int infile_fd, char **args, char **envp)
{
	if (dup2(infile_fd, 0) == -1)
		return (-6);
	close(infile_fd);
	if (dup2(fildes[0], 1) == -1)
		return (-6);
	close(fildes[0]);
	if (exec_cmd(args[3], envp) < 0)
		return (-7);
	return (0);
}

int	run_child_process(int fildes[2], int outfile_fd, char **args, char **envp)
{
	if (dup2(fildes[1], 0) == -1)
		return (-6);
	close(fildes[1]);
	if (dup2(outfile_fd, 1) == -1)
		return (-6);
	close(outfile_fd);
	if (exec_cmd(args[2], envp) == -1)
		return (-7);
	return (0);
}

int	exec_cmd(char *cmd, char **envp)
{
	char 	**split_cmd;
	char	*path;
	int		error;

	path = NULL;
	split_cmd = ft_split(cmd, ' ');
	if (split_cmd == NULL || split_cmd[0] == NULL)
	{
		ft_printf("Pipex: command not found: %s\n", cmd);
		return (-1);
	}
	error = build_path(path, cmd, envp);
	if (error < 0)
		return (error);
	execve(path, split_cmd, envp);
	free_split(split_cmd);
	return (error);
}
