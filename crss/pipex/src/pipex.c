#include "pipex.h"

static void	exec_command(t_pipex *pipex, int i, char **env)
{
	pipex->path = build_path(pipex->path_split,
			pipex->cmds[i][0]);
	if (!pipex->path)
		return_error(ERR_ENVP, pipex);
	execve(pipex->path, pipex->cmds[i], env);
	return_error(ERR_XCV, pipex);
}

static void	init_pipex(t_pipex **pipex, int argc, char **argv, char **env)
{
	*pipex = malloc(sizeof(t_pipex));
	if (*pipex == NULL)
		return_error(ERR_MLLC, *pipex);
	(*pipex)->path_split = ft_split(find_path(env), ':');
	(*pipex)->cmds = split_cmds(argc, argv);
	if (!(*pipex)->cmds)
		return_error(ERR_SPLT, *pipex);
	(*pipex)->in_fd = open(argv[0], O_RDONLY);
	if ((*pipex)->in_fd < ERR_NONE)
	{
		return_error(ERR_OPEN, *pipex);
		(*pipex)->in_fd = open ("/dev/null", O_RDONLY);
	}
	(*pipex)->of_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, CHMOD_RWRR);
}

static void	child_process(t_pipex *pipex, int i, int argc, char **env)
{
	dup2(pipex->in_fd, STDIN_FILENO);
	if (i == argc - 3)
	{
		if (pipex->of_fd < ERR_NONE)
			return_error(ERR_DUP2, pipex);
		dup2(pipex->of_fd, STDOUT_FILENO);
		close(pipex->of_fd);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	exec_command(pipex, i, env);
}

static void	parent_process(t_pipex *pipex, int i, int argc)
{
	close (pipex->pipe_fd[1]);
	if (i > 1)
		close (pipex->in_fd);
	if (i < argc - 3)
		pipex->in_fd = pipex->pipe_fd[0];
	else
		close (pipex->pipe_fd[0]);
}

void	pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		i;

	pipex = NULL;
	init_pipex(&pipex, argc, argv, env);
	i = 0;
	while (i < argc - 2)
	{
		if (i < argc - 3)
			if (pipe(pipex->pipe_fd) == ERR_GNRL)
				return_error(ERR_PIPE, pipex);
		pipex->pid = fork();
		if (pipex->pid < ERR_NONE)
			return_error(ERR_FORK, pipex);
		if (pipex->pid == ERR_NONE)
			child_process(pipex, i, argc, env);
		else
			parent_process(pipex, i, argc);
		i++;
	}
	fd_close_wait(pipex, argc);
	free_pipex(pipex);
}
