/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:52:33 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/21 19:39:48 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	nbr;
	long	sign;
	int		i;
	
	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

static int	atol_args(t_stacks **stacks, char **args)
{
	long	*atol;
	t_list	*node;

	atol = malloc(1 * sizeof(long));
	if (atol == NULL)
		return (-1);
	*atol = ft_atol(*args);
	if (*atol < INT_MIN || *atol > INT_MAX)
	{
		free(atol);
		return (-2);
	}
	node = ft_lstnew((int *)atol);
	if (node == NULL)
		return (-3);
	if (*atol < (*stacks)->min_val)
		(*stacks)->min_val = *atol;
	if (*atol > (*stacks)->max_val)
		(*stacks)->max_val = *atol;
	(*stacks)->mid_val = ((*stacks)->min_val + (*stacks)->max_val)/2;
	t_list *temp = (*stacks)->a;
	ft_lstadd_back(&temp, node);
	return (ERR_NONE);
}

int	parse_arg(t_stacks **stacks, char *arg)
{
	int		i;
	int		atol_args_err;
	char	**split_array;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0 && arg[i] != ' ')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	split_array = ft_split(arg, ' ');
	atol_args_err = atol_args(stacks, split_array);
	free_split(split_array);
	return (atol_args_err);
}
