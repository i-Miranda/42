/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 12:33:59 by ivmirand         ###   ########.fr       */
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

//desired argc
# define ARGC 5
//chmod permissions
# define CHMOD_RWRR 0644

typedef struct s_pipe
{
	char	*left_cmd;
	char	*right_cmd;
	int		fildes[2];
	int		fd_if;
	int		fd_of;
	pid_t	child_pid;
	pid_t	parent_pid;
} t_pipe;

//pipex functions
int		pipex(char **args, char *envp[]);
int		run_child_process(t_pipe *pipe_data, char *envp[]);
int		run_parent_process(t_pipe *pipe_data, char *envp[]);
int		exec_cmd(char *cmd, char **envp);

//init_pipex functions
t_pipe	*init_pipex(t_pipe *pipe_data, char **args, char *envp[]);

//pipex utils
void	return_error(int error);
int		build_path(char *path, char *cmd, char **envp);
void	free_split(char **split);
#endif
