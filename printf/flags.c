/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:01:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/22 09:34:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	basic_atoi(const char *str, size_t *i, int num)
{
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		if ((num > INT_MAX / 10)
			|| (num == INT_MAX / 10 && str[*i] - '0' > INT_MAX % 10))
			num = INT_MAX;
		else
			num = (num * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (num);
}

static int	get_width(const char *str, t_info *info, va_list args, size_t i)
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
		info->width = basic_atoi(str + i, &i, 0);
	}
	return (i);
}

static int	get_precision(const char *str, t_info *info, va_list args, size_t i)
{
	if (str[i] == '.' && str[i + 1] == '*')
	{
		i += 2;
		info->precision = va_arg(args, int);
	}
	else if (str[i] == '.')
	{
		i++;
		info->precision = basic_atoi(str, &i, 0);
	}
	return (i);
}

static size_t	get_flags(const char *after_pct, t_info *info, size_t i)
{
	while (after_pct[i] && ft_strchr("- +#0", after_pct[i]))
	{
		if (after_pct[i] == '-')
			info->dash = true;
		else if (after_pct[i] == ' ' && info->sign != '+')
			info->sign = ' ';
		else if (after_pct[i] == '+')
			info->sign = '+';
		else if (after_pct[i] == '#')
			info->sharp = true;
		else if (after_pct[i] == '0')
			info->padding = '0';
		i++;
	}
	return (i);
}

size_t	get_info(const char *after_pct, t_info *info, va_list args)
{
	size_t	i;

	i = 0;
	if (after_pct[i] && ft_strchr("- +#.*0123456789", after_pct[i]))
	{
		i += get_flags(after_pct, info, i);
		if (after_pct[i] && ft_strchr(".*123456789", after_pct[i]))
		{
			i += get_width(after_pct + i, info, args, 0);
			i += get_precision(after_pct + i, info, args, 0);
		}
	}
	if (after_pct[i] && !ft_strchr("cspdiuxX%", after_pct[i]))
		return (INT_MAX);
	else
		info->fmt = after_pct[i++];
	if (info->dash && info->padding == '0')
		info->padding = ' ';
	if (info->precision == INT_MAX)
		info->precision = -1;
	return (i);
}
