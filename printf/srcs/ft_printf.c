/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/19 06:50:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conversion(char *specifiers, t_info *info, va_list args)
{
	int		printed;
	char	*tmp;

	printed = 0;
	info->i += get_info(specifiers, info, args, &printed, 0);
	if (info->width == INT_MAX
		|| (info->precision == INT_MAX && !strchr("cs%", info->fmt))
		return (INT_MAX);
	if (info->fmt == 'c')
		printed += put_char(info, va_arg(args, unsigned char));
	else if (info->fmt == 's')
		printed += put_str(info, va_arg(args, char *);
	else if (info->fmt == 'p')
		printed += put_hex(info, va_arg(args, unsigned long long));
	else if (info->fmt == 'd' || info->fmt == 'i' || info->fmt == 'u')
		printed += put_int(info, args);
	else if (info->fmt == 'x' || info->fmt == 'X')
		printed += put_hex(info, va_arg(args, unsigned int));
	else if (info->fmt == '%')
		printed += put_char(info, '%');
	return (printed);
}

static void	init(t_info *info)
{
	info->fmt = '\0';
	info->precision = -1;
	info->width = 0;
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
