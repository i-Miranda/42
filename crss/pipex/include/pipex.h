/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/09 12:09:50 by ivmirand         ###   ########.fr       */
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
