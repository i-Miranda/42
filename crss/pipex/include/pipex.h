/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/13 13:16:54 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//read write access dup dup2 execve fork pipe unlink
# include <unistd.h>
//malloc free exit
# include <stdlib.h>
//perror 
# include <stdio.h>
//strerror
# include <string.h>
# include <errno.h>
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
# define ERR_OPNI -4
# define ERR_OPNO -5
# define ERR_FORK -6
# define ERR_INFL -7
# define ERR_CHMI -8 
# define ERR_CHMO -9 
# define ERR_CHMD -10 
# define ERR_NCMD 128
# define ERR_NULL 129
# define ERR_EXCV 127

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
	char	*no_such_file;
	char	*no_such_cmd;
	int		pipe_fd[2];
	pid_t	pid;
	int		in_fd;
	int		of_fd;
}	t_pipex;

//pipex functions
int		pipex(int argc, char **argv, char **env);

//pipex_utils functions
void	free_pipex(t_pipex *pipex);
void	fd_close_wait(t_pipex *pipex);
char	***split_cmds(int argc, char **argv);
char	*get_path(char **env);
char	*build_path(char **path_split, char *cmd);

//pipex_errors functions
int		return_error(int error, t_pipex *pipex);
#endif
