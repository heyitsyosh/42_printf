
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:29 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/12 02:41:04 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_str(char *input, size_t len, t_printinfo *info)
{
	if (len < INT_MAX)
		write(1, input, len);
	else
		len = INT_MAX;
	return (len);
}

int	no_conversion(char *input, t_printinfo *info)
{
	char	*percent_ptr;
	size_t	len;
	int		print_len;

	percent_ptr = ft_strchr(input, '%');
	if (!percent_ptr)
		len = ft_strlen(input);
	else
		len = percent_ptr - input;
	print_len = print_str(input, len);
	info->i += print_len;
	return (print_len);
}

int	put_str(char *arg, t_printinfo *info)
{
	size_t	arg_len;
	int		printed;

	printed = 0;
	if (arg == NULL)
	{
		free(arg);
		arg = ft_strdup("(null)");
		if (!arg)
			return (printed); // what kind of error handling should i do?
	}
	arg_len = ft_strlen(arg);
	if (info->precision != -1 && info->precision < arg_len)
		arg_len = info->precision;
	if (info->dash == true)
		printed += print_str(arg, arg_len);
	while (info->width-- > arg_len)
		printed += write(1, &info->padding, 1);
	if (info->dash == false)
		printed += print_str(arg, arg_len);
	return (printed);
}

int	put_char(unsigned char arg, t_printinfo *info)
{
	char *char_as_str;

	if (info->dash == true)
		printed += write(1, &arg, 1);
	while (info->width-- > arg_len)
		printed += write(1, &info->padding, 1);
	if (info->dash == false)
		printed += write(1, &arg, 1);
	return (printed);
}
