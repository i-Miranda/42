/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/19 13:13:32 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

// This should probably return a vertex struct of some sort
static t_vertex	*parse_vertex(int x, int y, int z, int color)
{
	t_vertex	*vertex;

	vertex = init_vertex(x, y, z, color);
	return (vertex);
}

static int	*parse_row (char **row_text)
{
	int		*row;
	long	atol;
	int		i;

	i = 0;
	while (row_text[i])
		i++;
	row = ft_calloc(i + 1, sizeof(int));
	if (!row)
		return (NULL);
	i = 0;
	while (row_text[i])
	{
		atol = ft_atol(row_text[i]);	
		if (atol < INT_MIN || atol > INT_MAX)
			row[i] = (int)atol;
		else
		{
			free(row);
			return (NULL);
		}
		i++;
	}
	return (row);
}

static int	parse_columns(int row_count, int *row, int height)
{
	int	col_count;
	t_vertex

	col_count = 0;
	(*fdf)->zero_vertex = parse_vertex(row_count, col_count, row[col_count], color);	
	while (row[col_count])
	{
		if ((*fdf)->zero_vertex == NULL)
		{
			free(*fdf);
			free(row);
			return ;
		}
		col_count++;
	}
}

void	parse_fdf(char *fdf_path, t_fdf **fdf)
{
	char	**nl_split;
	int		*fdf_row;	
	char 	*next_line; 
	int		row_count;
	int		col_count;
	int		fd;	
	
	fd = open(fdf_path, O_RDONLY);
	next_line = get_next_line(fd);
	if (!next_line)
		return ;	
	*fdf = ft_calloc(1 + 1, sizeof(t_fdf));
	if (*fdf == NULL)
		return ;
	row_count = 0;
	while (next_line)
	{
		nl_split = ft_split(next_line, ' ');
		if (nl_split == NULL)
		{
			free(*fdf);
			return ;
		}
		free(next_line);
		fdf_row = parse_row(nl_split);
		ft_free_split(nl_split);
		if (fdf_row == NULL)
		{
			free(*fdf);
			return ;
		}
		parse_columns(row_count,)
		free(fdf_row);
		next_line = get_next_line(fd);
		row_count++;
	}
	close(fd);
	(*fdf)->dimensions = init_vector3(row_count, col_count, 0);
	(*fdf)->origin = init_vector3(0, 0, 0);
	(*fdf)->scale = init_vector3(100, 100, 100);
}
