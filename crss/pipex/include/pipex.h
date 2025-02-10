/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 10:49:05 by ivmirand         ###   ########.fr       */
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

//desired argc
# define ARGC 5

//pipex functions
int		pipex(char **args, char *envp[]);
int		open_files(int *fd_in, int *fd_out, char *infile, char *outfile);
int		run_parent_process(int fildes[2], int infile_fd, char **args, char **envp);
int		run_child_process(int fildes[2], int outfile_fd, char **args, char **envp);
int		exec_cmd(char *cmd, char **envp);

//pipex utils
void	return_error(int error);
int		build_path(char *path, char *cmd, char **envp);
void	free_split(char **split);
#endif
