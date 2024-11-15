/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 00:45:23 by ivmirand         ###   ########.fr       */
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
size_t	ft_print_int(int nbr, char *flags);
size_t	ft_print_hex(int hex, int is_big, char *flags);
size_t	ft_print_uint(int u_int, char *flags);

//Text print functions
size_t	ft_print_char(int c, char *flags);
size_t	ft_print_string(char *str);
size_t	ft_print_address(void *addr, int is_big, char *flags);
size_t	ft_print_percent(void);

//Utils
char	*ft_check_padding(char *str);
char	*ft_check_flags(char *str);
#endif
