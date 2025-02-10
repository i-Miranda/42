#include "pipex.h"

int	pipex(char **args, char *envp[])
{
	t_pipe	*pipe_data;
	int		error;
		
	pipe_data = NULL;
	error = init_pipex(pipe_data, args);
	if (error != ERR_NONE)
		return (error);
	error = run_processes(pipe_data, envp);
	return (error);
}
