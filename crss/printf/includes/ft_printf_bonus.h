/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 12:16:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int		ft_printf(char const *str, ...);

//Number print functions
size_t	ft_print_hex_bonus(void *hex, int is_big, char *flags, int i);
size_t	ft_print_int_bonus(int nbr, char *flags);
size_t	ft_print_uint_bonus(unsigned int u_int, char *flags);

//Text print functions
size_t	ft_print_char_bonus(int c);
size_t	ft_print_string_bonus(char *str, char *flags);

//Flag print functions
size_t	ft_print_padding(char *output, char *flags);
#endif
