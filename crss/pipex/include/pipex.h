/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:37 by ivmirand         ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
//open close
# include <fcntl.h>
//wait waitpid
# include <sys/types.h>
# include <sys/wait.h>

# include "libft.h"

//Boolean constants
# define FALSE 0
# define TRUE 1

//error constants
# define ERR_NONE 0
# define ERR_GNRL -1
# define ERR_INPT -2
# define ERR_OPNI -3
# define ERR_CHMD -4 
# define ERR_CHMI -5 
# define ERR_CHMO -6 
# define ERR_MLLC 12
# define ERR_OPNO 126 
# define ERR_NCMD 127

//desired argc
# define ARGC 4

//argv constants
# define ARG_IF 0
# define ARG_LCMD 1
# define ARG_RCMD 2
# define ARG_OF 3

//chmod permissions
# define CHMOD_URR 0644

//if pid is 0...
# define CHILD_PID 0

//if env -i...
# define EMERGENCY_PATH "/home/ivmirand/bin: \
	/usr/local/sbin:/usr/local/bin: \
	/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin" 

typedef struct s_pipex
{
	char	***cmds;
	char	**path_split;
	char	*no_such_file;
	char	*no_such_cmd;
	int		pipe_fd[2];
	int		in_fd;
	int		of_fd;
}	t_pipex;

//pipex functions
int		pipex(int argc, char **argv, char **envp);

//pipex functions
void	init_pipex(t_pipex **pipex, int argc, char **argv, char **envp);
void	close_fds(t_pipex *pipex);
int		wait_and_close(t_pipex *pipex, pid_t pid1, pid_t pid2);

//pipex_errors functions
void	return_error(int error, t_pipex *pipex, int exitbool);

//pipex_utils functions
void	free_pipex(t_pipex *pipex);
char	***split_cmds(int argc, char **argv);
char	*get_path(char **envp);
char	*build_cmd_path(char **path_split, char *cmd);

#endif
