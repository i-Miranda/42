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

t_fdf	*parse_fdf(char *fdf_path)
{
	t_fdf	*fdf;
	char	**nl_split;
	int		*fdf_columns;	
	char 	*next_line; 
	int		row_count;
	int		col_count;
	int		fd;	
	
	fd = open(fdf_path, O_RDONLY);
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);	
	fdf = ft_calloc(1, sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	row_count = 0;
	while (next_line)
	{
		nl_split = ft_split(next_line, ' ');
		if (nl_split == NULL)
		{
			free(fdf);
			return (NULL);
		}
		free(next_line);
		fdf_columns = parse_row(nl_split);
		ft_free_split(nl_split);
		if (fdf_columns == NULL)
		{
			free(fdf);
			return (NULL);
		}
		col_count = 0;
		while (fdf_columns[col_count])
		{
			fdf->zero_vertex = parse_vertex(row_count, col_count, fdf_columns[col_count], -1);	
			if (fdf->zero_vertex == NULL)
			{
				free(fdf);
				free(fdf_columns);
				return (NULL);
			}
			col_count++;
		}
		free(fdf_columns);
		next_line = get_next_line(fd);
		row_count++;
	}
	close(fd);
	fdf->dimensions = init_vector3(row_count, col_count, 0);
	fdf->origin = init_vector3(0, 0, 0);
	fdf->scale = init_vector3(100, 100, 100);
	return (fdf);
}
