/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/30 18:03:08 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	link_rows(int next_row, t_fdf **fdf)
{
	t_coord *prev_coord;
	t_coord	*coord;
	int 	i;

	i = 0;
	prev_coord = (*fdf)->zero_coord;
	while (i < next_row - 1)
	{
		prev_coord = prev_coord->next_y;	
		i++;
	}
	coord = prev_coord->next_y;
	while (prev_coord->next_x != NULL)
	{
		prev_coord = prev_coord->next_x;
		coord = coord->next_x;
		prev_coord->next_y = coord;
	}
}

static int	parse_columns(int row_count, char **split, t_fdf **fdf)
{
	t_coord	*prev_coord;
	t_coord	*coord;
	int		col_count;

	col_count = 1;
	prev_coord = (*fdf)->zero_coord;
	while (prev_coord->next_y != NULL)
		prev_coord = prev_coord->next_y;
	while (split[col_count])
	{
		coord = init_coord(col_count, row_count, split[col_count]);
		prev_coord->next_x = coord;
		prev_coord = prev_coord->next_x;
		col_count++;
	}
	return (col_count);
}

static int parse_row(int row_count, char **split, t_fdf **fdf)
{
	t_coord *coord;

	if (row_count == 0)
		*fdf = init_fdf(0, row_count, split[0]);
	coord = (*fdf)->zero_coord;
	while (coord->next_y != NULL)
		coord = coord->next_y;
	if (row_count != 0)
	{
		coord->next_y = init_coord(0, row_count, split[0]); 
		coord = coord->next_y;
	}
	return (parse_columns(row_count, split, fdf));
}

static void	parse_fd(int fd, t_fdf **fdf)
{
	char	**nnl_split;
	char 	*next_line; 
	char 	*no_next_line; 
	int		row_count;

	next_line = get_next_line(fd);
	if (!next_line)
		return ;	
	row_count = 0;
	while (next_line)
	{
		no_next_line = ft_substr(next_line, 0, ft_strlen(next_line) - 1);
		free(next_line);
		nnl_split = ft_split(no_next_line, ' ');
		free(no_next_line);
		parse_row(row_count, nnl_split, fdf);
		ft_free_split(nnl_split);
		if (row_count > 0)
			link_rows(row_count, fdf);
		next_line = get_next_line(fd);
		row_count++;
	}
}

void	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	t_coord *coord;
	int		fd;	
	int		col_count;	
	int		row_count;	

	fd = open(fdf_path, O_RDONLY);
	parse_fd(fd, fdf);
	coord = (*fdf)->zero_coord;
	row_count = 0;
	col_count = 0;
	while (coord->next_y != NULL)
	{
		coord = coord->next_y;
		row_count++;
	}
	while (coord->next_x != NULL)
	{
		coord = coord->next_x;
		col_count++;
	}
	(*fdf)->dimensions = init_vertex(col_count, row_count, 0);
	(*fdf)->origin = init_vertex(0, 0, 0);
	(*fdf)->scale = init_vertex(1.0, 1.0, 1.0);
	close(fd);
}
