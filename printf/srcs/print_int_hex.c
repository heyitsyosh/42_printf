/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/19 13:32:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	put_num(char *num, t_info *info)
{
	int	num_len;
	int	length;

	num_len = ft_strlen(num);
	length = ft_max(info->precision, info->width);
	if (info->padding && ft_strchr("di", info->fmt) && num[0] != '-')
		printed += write(1, &info->padding, 1);
	if (info->dash == true)
		printed += print_str(num);
	while (length-- > printed + num_len)
		printed += write(1, &info->padding, 1);
	if (info->dash == false)
		printed += print_str(num);
	return (printed);
}

int	num_to_arr(va_list args, t_info *info)
{
	int					printed;
	char				*num;

	printed = 0;
	if (ft_strchr("di", info->fmt))
		num = ft_itoa(va_arg(args, int));
	else if (ft_strchr("pxX", info->fmt))
		num = u_itoa(ull, 16);
	else if (info->fmt == 'u')
		num = u_itoa(ull, 10);
	if (!num)
		return (INT_MAX);
	printed = put_num(num, info);
	free(num);
	return (printed);
}
