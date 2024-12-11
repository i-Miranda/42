/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/11 01:57:40 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
size_t	ft_print_hex(void *hex, int is_big, char *flags, int i);
size_t	ft_print_int(int nbr, char *flags);
size_t	ft_print_uint(unsigned int u_int, char *flags);

//Text print functions
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str, char *flags);
size_t	ft_print_address(void *addr, char *flags);
size_t	ft_print_percent(void);

//Flag print functions
size_t	ft_print_padding(char *output, char *flags);
#endif
