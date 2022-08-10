/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/11 04:15:29 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conversion(char *specifiers, t_printinfo *info, va_list args)
{
	int	printed_char_count;

	specifiers = check_flags(specifiers, info);
	printed_char_count = 1;

	return (printed_char_count);
}

void	init(t_printinfo *info)
{
	info->current_specifier = '\0';
	info->digits = 0;
	info->precision = 0;
	info->width = 0;
	info->dash = false;
	info->zero = 0;
	info->sharp = false;
	info->space = false;
	info->plus = false;
}

int	ft_printf(const char *input, ...)
{
	size_t		printed_count;
	size_t		tmp;
	t_printinfo	*info;
	va_list		args;

	printed_count = 0;
	info->i = 0;
	info->error = false;
	va_start(args, input);
	while (*(input + info->i) && info->error == false)
	{
		init(info);
		if (*(input + info->i) == '%')
			tmp += conversion(input + info->i + 1, args, info);
		else
			tmp += no_conversion(input + info->i, info);
		printed_count += tmp;
	}
	va_end(args);
	if (info->error == true)
		return (-1);
	return (printed_count);
}

//check overflow before addition, dont know how real printf handles int overflows yet
//if i send (input + i + 1) and recieve it as a pointer, if I move the pointer in that function, input changes right?
//idk confirm that later