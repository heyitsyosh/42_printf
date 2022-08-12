/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:15:35 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/13 02:49:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static long	make_l(const char *str, size_t *i, long num)
{
	while (*(str + *i) && (*(str + *i) >= '0' && *(str + *i) <= '9'))
	{
		if ((num > LONG_MAX / 10)
			|| (num == LONG_MAX / 10 && *(str + *i) - '0' > LONG_MAX % 10))
			return (LONG_MAX);
		num = (num * 10) + (*(str + *i) - '0');
		i++;
	}
	return (num);
}

size_t	printf_atoi(const char *str, t_printinfo *info)
{
	size_t	i;
	long	num;

	i = 0;
	num = make_l(str + 1, &i, 0);
	if (*str == '*' || num < INT_MAX)
		info->width = num;
	else if (*str == '.' || num < INT_MAX)
		info->precision = num;
	else if (*str == '0' || num < INT_MAX)
		info->zero = num;
	else if (ft_isdigit(*str) || num < INT_MAX)
		info->width = num;
	else
		info->error = true;
	return (i);
}
//what if after the flag is \0

char	check_flags(char *after_pct, t_printinfo *info, size_t i)
{
	while (*(after_pct + i) && !ft_strchr("cspdiuxX%", *(after_pct + i)))
	{
		if (*(after_pct + i) == '-')
			info->dash = true;
		else if (*(after_pct + i) == ' ')
			info->space = true;
		else if (*(after_pct + i) == '+')
			info->plus = true;
		else if (*(after_pct + i) == '#')
			info->sharp = true;
		if (!ft_strchr("*.0123456789", *(after_pct + i)))
			i++;
		if (*(after_pct + i) == '*')
			i += printf_atoi(*(after_pct + i), info);
		else if (*(after_pct + i) == '.')
			i += printf_atoi(*(after_pct + i), info);
		else if (*(after_pct + i) == '0')
			i += printf_atoi(*(after_pct + i), info);
		else if (ft_isdigit(*(after_pct + i)))
			i += printf_atoi(*(after_pct + i), info);
	}
	info->i += i;
	return (*(after_pct + i + 1));
}
