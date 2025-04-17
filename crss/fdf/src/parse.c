/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/17 12:29:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

static void	link_rows(int next_row, t_fdf **fdf)
{
	t_coord	*prev_coord;
	t_coord	*coord;
	int		i;

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

static int	parse_row(int row_count, char **split, t_fdf **fdf)
{
	t_coord	*coord;

	if ((*fdf)->zero_coord == NULL)
	{
		(*fdf)->zero_coord = init_coord(0, 0, split[0]);
		if ((*fdf)->zero_coord->local->z > (*fdf)->dimensions->z)
			(*fdf)->dimensions->z = (*fdf)->zero_coord->local->z;
	}
	coord = (*fdf)->zero_coord;
	while (coord->next_y != NULL)
		coord = coord->next_y;
	if (row_count != 0)
	{
		coord->next_y = init_coord(0, row_count, split[0]);
		if ((*fdf)->zero_coord->local->z > (*fdf)->dimensions->z)
			(*fdf)->dimensions->z = (*fdf)->zero_coord->local->z;
		coord = coord->next_y;
	}
	return (parse_columns(row_count, split, fdf));
}

void	parse_fd(int fd, t_fdf **fdf)
{
	char	**nl_split;
	char	*next_line;
	int		row_count;

	next_line = get_next_line(fd);
	if (!next_line)
		return ;
	row_count = 0;
	while (next_line)
	{
		loading_fdf(row_count);
		nl_split = ft_split(next_line, ' ');
		free(next_line);
		parse_row(row_count, nl_split, fdf);
		ft_free_split(nl_split);
		if (row_count > 0)
			link_rows(row_count, fdf);
		next_line = get_next_line(fd);
		row_count++;
	}
}

int	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	t_coord *coord;
	int		fd;
	int		col_count;
	int		row_count;

	fd = open(fdf_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	parse_fd(fd, fdf);
	coord = (*fdf)->zero_coord;
	row_count = 1;
	col_count = 1;
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
	(*fdf)->dimensions->x = col_count;
	(*fdf)->dimensions->y = row_count;
	close(fd);
	return (0);
}
