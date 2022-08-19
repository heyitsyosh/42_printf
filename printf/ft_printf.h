/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:46:50 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/20 07:27:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_printinfo
{
	size_t	i;
	char	fmt;	
	int		precision;
	int		width;
	bool	dash;
	char	padding;
	bool	sharp;
	char	sign;
}	t_info;

size_t	get_info(char *after_pct, t_info *info, va_list args, int *p, size_t i);

int		put_char(t_info *info, int chr);
int		put_str(t_info *info, char *str);
int		put_unsigned(t_info *info, unsigned long long ull);
int		put_signed(t_info *info, char *num);

int		no_conversion(char *input, t_info *info)
int		print_str(char *input, size_t len, t_info *info)
#endif