/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/08 18:53:38 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t check_flags()

size_t	conversion(char *specifier, va_list args)
{
	int	printed_char_count;

	specifier = check_flags;
	printed_char_count = 1;
	switch (*specifier)
	{
		case 'c':
		case 's':
		case 'p':
		case 'd':
		case 'i':
		case 'u':
		case 'x':
		case 'X':
		case '%':
	}
	return (printed_char_count);
}

void	init(t_printinfo *info)
{
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
	size_t		i;
	size_t		printed_count;
	size_t		tmp;
	t_printinfo	*info;
	va_list		args;

	i = 0;
	printed_count = 0;
	va_start(args, input);
	init(info);
	while (*(input + i))
	{
		if (*(input + i) == '%')
			tmp += conversion(input + i + 1, args, info);
		else
			tmp += no_conversion(input + i);
		//check overflow before addition, dont know how real printf handles int overflows yet
		i += tmp;
		printed_count += tmp;
	}
	va_end(args);
	return (printed_count);
}

//if i send (input + i + 1) and recieve it as a pointer, if I move the pointer in that function, input changes right?
//idk confirm that ltr