/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 02:34:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0

int		ft_printf(char const *str, ...);

//Number print functions
size_t	ft_print_int(int nbr);
size_t	ft_print_hex(int hex, int is_big);
size_t	ft_print_uint(int u_int);

//Text print functions
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str);
size_t	ft_print_address(void *addr, int is_big);
size_t	ft_print_percent(void);

#endif
