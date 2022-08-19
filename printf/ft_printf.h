/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:46:50 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/20 06:58:33 by myoshika         ###   ########.fr       */
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

size_t	get_info(const char *after_pct, t_info *info, va_list args, int *p);

int		put_char(t_info *info, int chr);
int		put_str(t_info *info, const char *str);
int		put_unsigned(t_info *info, unsigned long long ull);
int		put_signed(t_info *info, char *num);

int		no_conversion(const char *input, t_info *info);

char	*ft_ulltoa(unsigned long long ull, int base, t_info *info);
int		print_str(const char *input, size_t len);
#endif