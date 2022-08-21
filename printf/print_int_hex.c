/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/21 11:23:15 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	put_num_padding(int printed, int num_len, t_info *info)
{
	if (info->precision)
		while (info->precision-- > num_len)
			printed += write(1, &"0", 1);
	else
		while (info->width-- > printed + num_len)
			printed += write(1, &info->padding, 1);
	return (printed);
}

static int	put_num(char *num, t_info *info)
{
	int		num_len;
	int		printed;

	printed = 0;
	num_len = ft_strlen(num);
	// if (info->precision <= num_len)
	// 	info->precision = -1;
	// if (info->sign && ft_strchr("di", info->fmt)
	// 	&& (info->precision > -1 || (info->width > num_len + 1 && info->padding == '0'))
	// 	printed += write(1, &info->sign, 1);
	if (info->dash == true)
		printed += print_str(num, num_len);
	printed += put_num_padding(printed, num_len, info);
	// if (info->sign && ft_strchr("di", info->fmt)
	// 	&& !(info->width <= num_len + printed) && !(info->padding == '0'))
	// 	printed += write(1, &info->sign, 1);
	if (info->dash == false)
		printed += print_str(num, num_len);
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
