/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:55 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 19:30:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int		ft_printf(char const *str, ...);

//Number print functions
size_t	ft_print_hex_bonus(void *hex, int is_big, int i, char *flags);
size_t	ft_print_int_bonus(int nbr, char *flags);
size_t	ft_print_uint_bonus(unsigned int u_int, char *flags);

//Text print functions
size_t	ft_print_char_bonus(int c, char *flags);
size_t	ft_print_string_bonus(char *str, char *flags);

//Flag print functions
size_t	ft_print_padding(char *output, char *flags);
size_t	check_flags_for_minus(char *output, char *flags);

//Flag process functions
char	*ft_find_flags(char *c);
char	*ft_remove_flags(char *c);
#endif
