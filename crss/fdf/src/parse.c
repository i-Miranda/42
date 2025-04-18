/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/18 23:38:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	link_rows(int row_count, t_fdf **fdf)
{
	t_coord	*prev_coord;
	t_coord	*coord;
	int		i;

	i = 0;
	prev_coord = (*fdf)->zero_coord;
	while (i < row_count - 1)
	{
		loading_fdf(i, "Finding row links");
		prev_coord = prev_coord->next_y;
		i++;
	}
	coord = prev_coord->next_y;
	while (prev_coord->next_x != NULL)
	{
		loading_fdf(i, "Linking rows");
		prev_coord = prev_coord->next_x;
		coord = coord->next_x;
		prev_coord->next_y = coord;
		i++;
	}
}

static int	parse_columns(int row_count, char **split, t_fdf **fdf)
{
	t_coord	*prev_coord;
	t_coord	*coord;
	int		col_count;

	col_count = 1;
	ft_printf("Parsing columns in row %d\n", row_count);
	prev_coord = (*fdf)->zero_coord;
	while (prev_coord->next_y != NULL)
		prev_coord = prev_coord->next_y;
	while (split[col_count])
	{
		loading_fdf(col_count, NULL);
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

	ft_printf("Initializing row %d\n", row_count);
	if ((*fdf)->zero_coord == NULL)
		(*fdf)->zero_coord = init_coord(0, 0, split[0]);
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

void	parse_fd(int fd, t_fdf **fdf)
{
	char	**nl_split;
	char	*next_line;
	int		row_count;

	next_line = get_next_line(fd);
	if (!next_line)
		return ;
	row_count = 0;
	ft_printf("Parsing fdf\n");
	while (next_line)
	{
		loading_fdf(row_count, NULL);
		nl_split = ft_split(next_line, ' ');
		free(next_line);
		(*fdf)->dimensions->x = parse_row(row_count, nl_split, fdf);
		ft_free_split(nl_split);
		if (row_count > 0)
			link_rows(row_count, fdf);
		next_line = get_next_line(fd);
		row_count++;
		(*fdf)->dimensions->y++;
	}
	ft_printf("Fdf parse complete\n");
}

int	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	int		fd;

	fd = open(fdf_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	parse_fd(fd, fdf);
	return (close(fd));
}
