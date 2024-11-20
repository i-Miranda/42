/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/20 20:00:48 by ivmirand         ###   ########.fr       */
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
# ifndef __unix
#  define NIL "0x0"	
# else
#  define NIL "(nil)"	
# endif

int		ft_printf(char const *str, ...);

//Number print functions
size_t	ft_print_hexbyte(unsigned char byte, int is_big);
size_t	ft_print_hex(void *hex, int is_big, char *flags);
size_t	ft_print_int(int nbr);
size_t	ft_print_uint(unsigned int u_int);

//Text print functions
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str);
size_t	ft_print_address(void *addr, char *flags);
size_t	ft_print_percent(void);

#endif
