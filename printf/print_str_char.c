
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

#include "libft/libft.h"
#include "ft_printf.h"

int	print_str(const char *input, size_t len)
{
	if (len < INT_MAX)
		write(1, input, len);
	else
		len = INT_MAX;
	return (len);
}

int	no_conversion(const char *input, t_info *info)
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

int	put_str(t_info *info, const char *str)
{
	size_t	s_len;
	int		printed;

	printed = 0;
	if (str == NULL)
	{
		free((char *)str); // can i do this??
		str = ft_strdup("(null)");
		if (!str)
			return (INT_MAX);
	}
	s_len = ft_strlen(str);
	if (info->precision > -1 && (size_t)info->precision < s_len)
		s_len = info->precision;
	if (info->dash)
		printed += print_str(str, s_len);
	if (info->width > -1)
		while ((size_t)info->width-- > s_len)
			printed += write(1, &info->padding, 1);
	if (!info->dash)
		printed += print_str(str, s_len);
	free((char *)str);
	return (printed);
}

int	put_char(t_info *info, int chr)
{
	int		printed;

	printed = 0;
	if (info->dash)
		printed += write(1, &chr, 1);
	while (info->width-- > 1)
		printed += write(1, &info->padding, 1);
	if (!info->dash)
		printed += write(1, &chr, 1);
	return (printed);
}