/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/18 03:56:06 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conversion(char *specifiers, t_printinfo *info, va_list args)
{
	int		printed;
	char	*tmp;

	printed = 0;
	info->i += check_flags(specifiers, info, args, 0);
	if (info->width >= INT_MAX)
		return (INT_MAX);
	if (info->fmt == 'c')
		printed += put_char(va_arg(args, unsigned char), info);
	else if (info->fmt == 's')
		printed += put_str(va_arg(args, char *), info);
	else if (info->fmt == 'p')
		printed += put_hex(va_arg(args, unsigned long long), info);
	else if (info->fmt == 'd' || info->fmt == 'i' || info->fmt == 'u')
		printed += put_int(args, info);
	else if (info->fmt == 'x' || info->fmt == 'X')
		printed += put_hex(va_arg(args, unsigned int), info);
	else if (info->fmt == '%')
		printed += put_char('%', info);
	return (printed);
}

void	init(t_printinfo *info)
{
	info->fmt = '\0';
	info->precision = -1;
	info->width = 0;
	info->dash = false;
	info->zero = ' ';
	info->sharp = false;
	info->space = false;
	info->plus = false;
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	t_printinfo	*info;
	size_t		tmp;
	size_t		printed;

	info->error = false;
	info->i = 0;
	printed = 0;
	va_start(args, input);
	while (input[info->i] || printed < INT_MAX)
	{
		init(info);
		if (input[info->i] == '%')
			tmp += conversion(input + info->i++, info, args);
		else
			tmp += no_conversion(input + info->i, info);
		printed += tmp;
	}
	va_end(args);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}
