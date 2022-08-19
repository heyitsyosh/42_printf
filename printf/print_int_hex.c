/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/20 04:36:31 by myoshika         ###   ########.fr       */
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
	if (info->sign && info->padding == '0' && ft_strchr("di", info->fmt))
		printed += write(1, &info->sign, 1);
	if (info->dash == true)
		printed += print_str(num);
	while (length-- > printed + num_len)
		printed += write(1, &info->padding, 1);
	if (info->sign && info->padding == ' ' && ft_strchr("di", info->fmt))
		printed += write(1, &info->sign, 1);
	if (info->dash == false)
		printed += print_str(num);
	return (printed);
}

int	put_unsigned(t_info *info, unsigned long long ull)
{
	int		printed;
	char	*num;

	printed = 0;
	if (info->fmt == 'u')
		num = ft_ulltoa(ull, 10, info);
	else
		num = ft_ulltoa(ull, 16, info);
	if (!num)
		return (INT_MAX);
	else
		printed = put_num(num, info);
	free(num);
	return (printed);
}

int	put_signed(t_info *info, char *num)
{
	int		printed;

	if (!num)
		return (INT_MAX);
	if (num[0] == '-')
	{
		info->sign = '-';
		printed = put_num(num + 1, info);
	}
	else
		printed = put_num(num, info);
	free (num);
	return (printed);
}
