/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 01:25:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_coord(int y, int x, char *c_split, t_fdf *fdf)
{
	char	**clr_split;
	t_coord	*current;

	clr_split = ft_split(c_split, ',');
	current = &fdf->coords[y * fdf->width + x];
	current->local = init_vertex(x, y, ft_atoi(clr_split[0]));
	current->world = init_vertex(-1, -1, -1);
	current->color_hex = WHITE;
	if (clr_split[1] != NULL)
		current->color_hex = rgb_to_rgba(ft_atoi_base(clr_split[1], 16), 0xFF);
	else if (current->local.z != 0)
		current->color_hex = get_rgba((char)current->local.x * 10,
				(char)current->local.y * 10, (char)current->local.z * 10, 255);
	ft_free_split(clr_split);
}

static void	parse_row(int y, char **split, t_fdf **fdf)
{
	int		x;

	x = 0;
	while (x < (*fdf)->width)
	{
		loading_fdf(x, "Parsing coord");
		parse_coord(y, x, split[x], *fdf);
		x++;
	}
	ft_printf("\n");
}

static int	parse_fd(char *fdf_path, t_fdf **fdf)
{
	char	**nl_split;
	char	*next_line;
	int		fd;
	int		row_count;

	fd = open(fdf_path, O_RDONLY);
	next_line = get_next_line(fd);
	if (!next_line)
		return (-1);
	row_count = 0;
	while (next_line)
	{
		loading_fdf(row_count, "Parsing row");
		nl_split = ft_split(next_line, ' ');
		free(next_line);
		parse_row(row_count, nl_split, fdf);
		ft_free_split(nl_split);
		next_line = get_next_line(fd);
		row_count++;
	}
	ft_printf("Fdf parse complete\n");
	return (close(fd));
}

static	int	set_fdf_dmns(char *fdf_path, t_fdf **fdf)
{
	char	**nl_split;
	char	*next_line;
	int		fd;

	fd = open(fdf_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	next_line = get_next_line(fd);
	if (!next_line)
		return (-1);
	nl_split = ft_split(next_line, ' ');
	while (nl_split[(*fdf)->width])
		(*fdf)->width++;
	ft_free_split(nl_split);
	while (next_line)
	{
		loading_fdf((*fdf)->height, "Getting Height");
		free(next_line);
		next_line = get_next_line(fd);
		(*fdf)->height++;
	}
	ft_printf("\n");
	return (close(fd));
}

int	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	if (set_fdf_dmns(fdf_path, fdf) == -1)
		return (-1);
	(*fdf)->coords = ft_calloc((*fdf)->height * (*fdf)->width, sizeof(t_coord));
	return (parse_fd(fdf_path, fdf));
}
