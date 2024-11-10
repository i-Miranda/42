/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/10 14:20:56 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

#define TRUE 1
#define FALSE 0

int	ft_printf(char const *str, ...);

//Number print functions
int	ft_print_int(int nbr);
int	ft_print_hex(int hex, int is_big);

//Text print functions
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_address(void *addr);
int	ft_print_percent(void);
