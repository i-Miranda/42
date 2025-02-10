/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//read write access dup dup2 execve fork pipe unlink
# include <unistd.h>
//malloc free exit
# include <stdlib.h>
//perror strerror
# include <stdio.h>
//open close
# include <fcntl.h>
//wait waitpid
# include <sys/wait.h>

# include "libft.h"

//error constants
# define ERR_NONE 0
# define ERR_GNRL -1
# define ERR_INPT -2
# define ERR_PIPE -3
# define ERR_OPEN -4
# define ERR_FORK -5
# define ERR_ACS -6
# define ERR_DUP2 -7
# define ERR_XCV -8
# define ERR_WTPD -9
# define ERR_ENVP -10
# define ERR_MLLC -11
# define ERR_PRSA -12
# define ERR_PRSC -13

//desired argc
# define ARGC 5
//chmod permissions
# define CHMOD_RWRR 0644

typedef struct s_pipe
{
	char	***cmds;
	char	**args;
	char	*if_path;
	char	*of_path;
	pid_t	pid;
	int		fildes[2];
	int		argc;
} t_pipe;

//pipex functions
int		pipex(int argc, char **args, char *envp[]);
void	free_pipex(t_pipe *pipe_data);

//init_pipex functions
int		init_pipex(t_pipe **pipe_data, char **args, int argc);

//run_process functions
int		run_processes(t_pipe **pipe_data, char *envp[]);

//pipex utils
void	return_error(int error);
void	free_split(char **split);
int		build_path(char *path, char *cmd, char *envp[]);
int		parse_cmds(t_pipe **pipe_data, char **args);
int		parse_args(t_pipe **pipe_data, char **args, int argc);

#endif
