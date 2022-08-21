/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:30:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/22 06:02:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	get_ull_len(unsigned long long ull, int base)
{
	int	digits;

	digits = 0;
	if (ull == 0)
		digits++;
	while (ull != 0)
	{
		ull /= base;
		digits++;
	}
	return (digits);
}

static void	make_arr(char *arr, unsigned long long ull, int base, t_info *info)
{
	const char			*lower = "0123456789abcdef";
	const char			*upper = "0123456789ABCDEF";
	unsigned long long	div;

	div = 1;
	while (ull / base >= div)
		div *= base;
	while (div != 0)
	{
		if (info->fmt == 'X')
			*arr = upper[ull / div];
		else
			*arr = lower[ull / div];
		ull %= div;
		div /= base;
		arr++;
	}
	*arr = '\0';
}

char	*ft_ulltoa(unsigned long long ull, int base, t_info *info)
{
	char		*arr;
	int			digits;

	digits = get_ull_len(ull, base);
	if (info->fmt == 'p')
		digits += 2;
	arr = (char *)malloc(digits + 1);
	if (!arr)
		return (NULL);
	if (info->fmt == 'p')
	{
		arr[0] = '0';
		arr[1] = 'x';
		make_arr(arr + 2, ull, base, info);
	}
	else
		make_arr(arr, ull, base, info);
	return (arr);
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


// char	*ft_ulltoa(unsigned long long ull, int base, t_info *info)
// {
// 	char		*arr;
// 	int			digits;

// 	digits = get_ull_len(ull, base);
// 	if ((digits >= INT_MAX - 1 && info->sharp && ft_strchr("xX", info->fmt))
// 		|| (digits == INT_MAX - 1 && info->fmt == 'p')
// 		|| digits == INT_MAX)
// 		return (NULL);
// 	else if (info->fmt == 'p' || (info->sharp && ft_strchr("xX", info->fmt)))
// 		digits += 2;
// 	arr = (char *)malloc(digits + 1);
// 	if (!arr)
// 		return (NULL);
// 	if (info->fmt == 'p' || (info->sharp && ft_strchr("xX", info->fmt) && ull))
// 	{
// 		arr[0] = '0';
// 		if (info->fmt != 'p')
// 			arr[1] = info->fmt;
// 		else
// 			arr[1] = 'x';
// 		make_arr(arr + 2, ull, base, info);
// 	}
// 	else
// 		make_arr(arr, ull, base, info);
// 	return (arr);
// }