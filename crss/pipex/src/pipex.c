#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	t_pipe	*pipe_data;
	int		error;
		
	error = init_pipex(pipe_data, args, envp) 
	if (error != ERR_NONE)
		return (error);
	if (pipe_data->child_pid == ERR_NONE)
		run_child_process(pipe_data, envp);
	if (pipe_data->parent_pid == ERR_NONE)
		run_parent_process(pipe_data, envp);
	if (access(args[0], R_OK) != ERR_NONE || access(args[3], W_OK) != ERR_NONE)
		return (ERR_ACS);	
	if (waitpid(child_pid, NULL, 0) == ERR_GNRL ||
			waitpid(parent_pid, NULL, 0) == ERR_GNRL)
		return (ERR_WTPD);
	return (ERR_NONE);
}


int	run_child_process(t_pipe *pipe_data, char *envp[])
{
	if (dup2(pipe_data->fd_if, 0) == ERR_GNRL)
		return (ERR_DUP2);
	close(pipe_data->fd_if);
	if (dup2(pipe_data->fildes[0], 1) == ERR_GNRL)
		return (ERR_DUP2);
	close(pipe_data->fildes[0]);
	if (exec_cmd(pipe_data->left_cmd, envp) < ERR_NONE)
		return (ERR_XCV);
	return (ERR_NONE);
}

int	run_parent_process(t_pipe *pipe_data, char *envp[])
{
	if (dup2(pipe_data->fildes[1], 0) == ERR_GNRL)
		return (ERR_DUP2);
	close(pipe_data->fildes[1]);
	if (dup2(pipe_data->fd_of, 1) == ERR_GNRL)
		return (ERR_DUP2);
	close(fd_of);
	if (exec_cmd(pipe_data->right_cmd, envp) == ERR_GNRL)
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
