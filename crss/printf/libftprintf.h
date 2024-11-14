/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/13 16:35:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

int		ft_printf(char const *str, ...);

//Number print functions
size_t	ft_print_int(int nbr);
size_t	ft_print_hex(int hex, int is_big);
size_t	ft_print_udec(int u_float);

//Text print functions
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str);
size_t	ft_print_address(void *addr, int is_big);
size_t	ft_print_percent(char *str);

//Utils
size_t	ft_check_flags(int c);

#endif
