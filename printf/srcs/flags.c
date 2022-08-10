/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:15:35 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/11 04:59:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	is_whitespace(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

static long	make_l(const char *str, size_t i, int sign, long num)
{
	//(SIZE_T_MAX) 
	while (*(str + i) && (*(str + i) >= '0' && *(str + i) <= '9'))
	{
		if (sign == 1 && ((num > LONG_MAX / 10)
				|| (num == LONG_MAX / 10 && *(str + i) - '0' > LONG_MAX % 10)))
			return (LONG_MAX);
		else if (sign == -1 && ((num < min / 10)
				|| (num == min / 10 && *(str + i) - '0' > min % 10 * -1)))
			return (LONG_MIN);
		num = (num * 10) + sign * (*(str + i) - '0');
		i++;
	}
	return (num);
}

int	printf_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	num;

	sign = 1;
	i = 0;
	while (is_whitespace(*(str + i)))
		i++;
	if ((*(str + i) == '+' || *(str + i) == '-') && *(str + i))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	num = make_l(str, i, sign, 0);
	return ((int)num);
}

size_t	check_flags(char *after_pct, t_printinfo *info)
{
	size_t		i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", *(after_pct + i)))
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
			i += find_flag_num(*(after_pct + i), info);
		else if (*(after_pct + i) == '.')
			i += find_flag_num(*(after_pct + i), info);
		else if (*(after_pct + i) == '0')
			i += find_flag_num(*(after_pct + i), info);
		else if (ft_isdigit(*(after_pct + i)))
			i += find_flag_num(*(after_pct + i), info);
	}
	return (i);
}
