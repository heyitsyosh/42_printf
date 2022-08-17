/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:15:35 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/18 05:49:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static long	basic_atol(const char *str, size_t *i, long num)
{
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		if ((num > LONG_MAX / 10)
			|| (num == LONG_MAX / 10 && str[*i] - '0' > LONG_MAX % 10))
			return (LONG_MAX);
		num = (num * 10) + (str[*i] - '0');
		*i++;
	}
	return (num);
}

int	get_width(const char *str, t_printinfo *info, va_list args, size_t i)
{
	if (str[i] == '*' && str[i + 1] != '.')
	{
		i += 2;
		info->width = va_arg(args, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->dash = true;
		}
	}
	else if (ft_isdigit(str[i]))
	{
		info->width = basic_atol(str + i, &i, 0);
	}
	return (i);
}

int	get_precision(const char *str, t_printinfo *info, va_list args, size_t i)
{
	if (str[i] == '*' && str[i + 1] == '.')
	{
		i += 2;
		info->precision = va_arg(args, int);
		if (info->precision < -1)
			info->precision = -1;
	}
	else if (str[i] == '.')
	{
		i++;
		info->precision = basic_atol(str + i, &i, 0);
	}
	return (i);
}

size_t	get_flags(char *after_pct, t_printinfo *info, size_t i)
{
	while (after_pct[i] && ft_strchr("- +#", after_pct[i]))
	{
		if (after_pct[i] == '-')
			info->dash = true;
		else if (after_pct[i] == ' ')
			info->space = true;
		else if (after_pct[i] == '+')
			info->plus = true;
		else if (after_pct[i] == '#')
			info->sharp = true;
		i++;
	}
	return (i);
}

size_t	store_info(char *after_pct, t_printinfo *info, va_list args, size_t i)
{
	while (after_pct[i] && ft_strchr("- +#.*0123456789", after_pct[i]))
	{
		i += get_flags(after_pct, info, i);
		if (after_pct[i] && ft_strchr(".*0123456789", after_pct[i]))
		{
			i += get_width(after_pct + i, info, args, 0);
			i += get_precision(after_pct + i, info, args, 0);
		}
	}
	if (!ft_strchr("cspdiuxX%", after_pct[i]))
		i = no_conversion(after_pct, info);
	else
	{
		info->fmt = after_pct[i];
		info->i += i;
	}
	return (i);
}
