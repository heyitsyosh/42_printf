/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/22 16:26:54 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static int	put_space_padding(int flags, int num_len, t_info *info)
{
	int	pad_count;

	pad_count = 0;
	if (info->sign != '\0')
		flags += 1;
	if (info->sharp == true)
		flags += 2;
	if (info->precision > -1)
		while (info->width-- > info->precision + flags)
			pad_count += write(1, &info->padding, 1);
	else
		while (info->width-- > num_len + flags)
			pad_count += write(1, &info->padding, 1);
	return (pad_count);
}

static int	put_zero_padding(int flags, int num_len, t_info *info)
{
	int	pad_count;

	pad_count = 0;
	if (info->precision > -1 && info->precision > num_len)
		while (info->precision-- > num_len)
			pad_count += write(1, &"0", 1);
	else if (info->padding == '0')
		while (info->width-- > num_len + flags)
			pad_count += write(1, &info->padding, 1);
	return (pad_count);
}

	// if ((call == 1 && (info->dash
	// 			|| (info->width >= num_len + 1 && info->padding == '0')))
	// 	|| (call == 2 && !info->dash))

static int	put_flag(char flag, int call, t_info *info)
{
	int	flag_count;

	flag_count = 0;
	if ((call == 1 && info->precision == -1 && info->dash)
		|| (call == 2 && !info->dash))
	{
		if (flag == '#')
		{
			flag_count += write(1, &"0", 1);
			if (info->fmt == 'p')
				flag_count += write(1, &"x", 1);
			else
				flag_count += write(1, &info->fmt, 1);
			info->sharp = false;
		}
		else
		{
			flag_count += write(1, &info->sign, 1);
			info->sign = '\0';
		}
	}
	return (flag_count);
}

static void	set_up(char *num, int *num_len, t_info *info)
{
	if (info->precision == 0 && num[0] == '0')
	{
		*num = '\0';
		*num_len = 0;
	}
	if (info->precision > -1)
		info->padding = ' ';
	if (info->precision <= *num_len)
		info->precision = -1;
}

int	put_num(char *num, int num_len, int printed, t_info *info)
{
	int	printed_flags;

	printed_flags = 0;
	set_up(num, &num_len, info);
	if (info->sign && ft_strchr("di", info->fmt))
		printed_flags = put_flag(info->sign, 1, info);
	if (info->sharp && ft_strchr("pxX", info->fmt))
		printed_flags = put_flag('#', 1, info);
	if (info->dash == true && info->precision == -1 && *num)
		printed += print_str(num, num_len);
	printed += put_space_padding(printed_flags, num_len, info);
	if (info->sign && ft_strchr("di", info->fmt))
		printed_flags += put_flag(info->sign, 2, info);
	if (info->sharp && ft_strchr("pxX", info->fmt))
		printed_flags += put_flag('#', 2, info);
	printed += put_zero_padding(printed_flags, num_len, info);
	if (*num)
		printed += print_str(num, num_len);
	return (printed + printed_flags);
}
