/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:19:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/12 11:06:17 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

// This should probably return a vertex struct of some sort
static int	*parse_column(char *column)
{
	char	**vertex_data;
	
	if (column != NULL)
		return (NULL);
	
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
			//abort
		i++;
	}
	return (row);
}

char	*parse_fdf(char *fdf_path)
{
	int 	**fdf_rows;
	char	**nl_split;
	int		*fdf_columns;	
	char 	*next_line;
	int		fd;	
	
	fd = open(fdf_path, O_RDONLY);
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);	
	while (next_line)
	{
		nl_split = ft_split(next_line, ' ');
		if (nl_split == NULL)
			return (NULL);
		free(next_line);
		fdf_columns = parse_row(nl_split);
		if (fdf_columns == NULL)
			return (NULL);
		//append fdf_columns to fdf_rows
		next_line = get_next_line(fd);
	}
	close(fd);
	return (fdf_rows);
}
