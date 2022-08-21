/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/21 17:35:36 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	put_num_padding(int sign, int num_len, t_info *info)
{
	int	padding_count;

	padding_count = 0;
	if (info->sign != '\0')
		sign += 1;
	if (info->precision > -1)
		while (info->precision-- > num_len)
			padding_count += write(1, &"0", 1);
	else
		while (info->width-- > num_len + sign)
			padding_count += write(1, &info->padding, 1);
	return (padding_count);
}

static int	put_num(char *num, int num_len, t_info *info)
{
	int	printed_sign;
	int	printed;

	printed = 0;
	printed_sign = 0;
	if (info->precision == 0 && num[0] == '0')
		return (0);
	if (info->precision <= num_len)
		info->precision = -1;
	if (info->sign && ft_strchr("di", info->fmt)
		&& (info->precision > -1 || (info->precision == -1 && info->dash)
			|| (info->width >= num_len + 1 && info->padding == '0')))
	{
		printed_sign += write(1, &info->sign, 1);
		info->sign = '\0';
	}
	if (info->dash == true)
		printed += print_str(num, num_len);
	printed += put_num_padding(printed_sign, num_len, info);
	if (info->sign && ft_strchr("di", info->fmt) && !info->dash)
		printed_sign += write(1, &info->sign, 1);
	if (info->dash == false)
		printed += print_str(num, num_len);
	return (printed + printed_sign);
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
		printed = put_num(num, (int)ft_strlen(num), info);
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
		printed = put_num(num + 1, (int)ft_strlen(num + 1), info);
	}
	else
		printed = put_num(num, (int)ft_strlen(num), info);
	free (num);
	return (printed);
}
