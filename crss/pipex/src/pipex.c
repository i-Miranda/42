#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	int		fildes[2];
	int		fd_infile;
	int		fd_outfile;
	pid_t	child_pid;
	pid_t	parent_pid;

	if (pipe(fildes) == ERR_GNRL)
		return (ERR_PIPE);
	if (open_files(&fd_infile, &fd_outfile, args[0], args[3]) == ERR_GNRL)
		return (ERR_OPEN);
	parent_pid = fork();	
	child_pid = fork();	
	if (parent_pid == ERR_GNRL || child_pid == ERR_GNRL)
		return (ERR_FORK);
	if (parent_pid == ERR_NONE)
		run_parent_process(fildes, fd_infile, args, envp);
	if (child_pid == ERR_NONE)
		run_child_process(fildes, fd_outfile, args, envp);
	if (access(args[0], R_OK) != ERR_NONE || access(args[3], W_OK) != ERR_NONE)
		return (ERR_ACS);	
	if (waitpid(child_pid, NULL, 0) == ERR_GNRL ||
			waitpid(parent_pid, NULL, 0) == ERR_GNRL)
		return (ERR_WTPD);
	return (ERR_NONE);
}

int open_files(int *fd_in, int *fd_out, char *infile, char *outfile)
{
	*fd_in = open(infile, O_RDONLY | O_CREAT);
	*fd_out = open(outfile, O_RDWR | O_CREAT, 0644);
	if (*fd_in == ERR_GNRL || *fd_out == ERR_GNRL)
		return (ERR_GNRL);
	return (ERR_NONE);
}

int	run_parent_process(int fildes[2], int infile_fd, char **args, char **envp)
{
	if (dup2(infile_fd, 0) == ERR_GNRL)
		return (ERR_DUP2);
	close(infile_fd);
	if (dup2(fildes[0], 1) == ERR_GNRL)
		return (ERR_DUP2);
	close(fildes[0]);
	if (exec_cmd(args[3], envp) < ERR_NONE)
		return (ERR_XCV);
	return (ERR_NONE);
}

int	run_child_process(int fildes[2], int outfile_fd, char **args, char **envp)
{
	if (dup2(fildes[1], 0) == ERR_GNRL)
		return (ERR_DUP2);
	close(fildes[1]);
	if (dup2(outfile_fd, 1) == ERR_GNRL)
		return (ERR_DUP2);
	close(outfile_fd);
	if (exec_cmd(args[2], envp) == ERR_GNRL)
		return (ERR_XCV);
	return (ERR_NONE);
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
		return (ERR_GNRL);
	}
	error = build_path(path, cmd, envp);
	if (error < ERR_NONE)
		return (error);
	execve(path, split_cmd, envp);
	free_split(split_cmd);
	return (error);
}
