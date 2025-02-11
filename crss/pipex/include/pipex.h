/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 12:28:41 by ivmirand         ###   ########.fr       */
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
# define ERR_DUP2 -6
# define ERR_EXCV -7
# define ERR_ENVP -8
# define ERR_MLLC -9
# define ERR_SPLT -10

//desired argc
# define ARGC 4
//argv constants
# define ARG_IF 0
# define ARG_LCMD 1
# define ARG_RCMD 2
# define ARG_OF 3

//chmod permissions
# define CHMOD_RWRR 0644

typedef struct s_pipex
{
	char	***cmds;
	char	**path_split;
	char	*path;
	int		pipe_fd[2];
	pid_t	pid;
	int		in_fd;
	int		of_fd;
}	t_pipex;

//pipex functions
void	pipex(int argc, char **argv, char **env);

//pipex_utils functions
void	return_error(int error, t_pipex *pipex);
void	fd_close_wait(t_pipex *pipex);
char	***split_cmds(int argc, char **argv);
char	*find_path(char **env);
char	*build_path(char **path_split, char *command);

void	free_pipex(t_pipex *pipex);
#endif
