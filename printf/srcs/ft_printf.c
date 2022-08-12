/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 05:44:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/13 02:59:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conversion(char *specifiers, t_printinfo *info)
{
	int	printed_char_count;

	info->current_specifier = check_flags(specifiers, info, 0);
	if (!info->current_specifier)
	{
		info->error = true;
		info->i++;
		return (0);
	}
	switch(info->current_specifier)
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
	info->current_specifier = '\0';
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
	size_t		tmp;
	t_printinfo	*info;

	info->printed = 0;
	info->i = 0;
	va_start(info->args, input);
	while (*(input + info->i))
	{
		init(info);
		if (*(input + info->i) == '%')
			tmp += conversion(input + info->i++, info); //test the ++ bit
		else
			tmp += no_conversion(input + info->i, info);
		info->printed += tmp;
	}
	va_end(info->args);
	if (info->printed >= INT_MAX || info->error == true)
		return (-1);
	return (info->printed);
}

//check overflow before addition, dont know how real printf handles int overflows yet
//if i send (input + i + 1) and recieve it as a pointer, if I move the pointer in that function, input changes right?
//idk confirm that later

//how to use args??
