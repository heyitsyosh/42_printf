/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/19 10:10:45 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	conversion(char *specifiers, t_info *info, va_list args)
{
	int		printed;
	char	*tmp;

	printed = 0;
	info->i += get_info(specifiers, info, args, &printed, 0);
	if (info->width == INT_MAX
		|| (info->precision == INT_MAX && ft_strchr("pdiuxX ", info->fmt)))
		return (INT_MAX);
	if (info->fmt == 'c')
		printed += put_char(info, va_arg(args, int));
	else if (info->fmt == 's')
		printed += put_ptr(info, va_arg(args, char *));
	else if (ft_strchr("pdiuxX", info->fmt))
		printed += put_int_hex(info, args);
	else if (info->fmt == '%')
		printed += put_char(info, '%');
	return (printed);
}

static void	init(t_info *info)
{
	info->fmt = ' ';
	info->precision = -1;
	info->width = -1;
	info->dash = false;
	info->zero = ' ';
	info->sharp = false;
	info->sign = '\0';
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	t_info		*info;
	size_t		printed;

	info->error = false;
	info->i = 0;
	printed = 0;
	va_start(args, input);
	while (input[info->i] || printed < INT_MAX)
	{
		init(info);
		if (input[info->i] == '%')
			printed += conversion(input + info->i++, info, args);
		else
			printed += no_conversion(input + info->i, info);
	}
	va_end(args);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}
