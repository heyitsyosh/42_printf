/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:30:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/20 07:06:29 by myoshika         ###   ########.fr       */
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
	while (ull != 0 && digits < INT_MAX)
	{
		ull /= base;
		digits++;
	}
	return (digits);
}

static void	put_in_digits(char *arr, unsigned long long ull, int base, t_info *info)
{
	const char		*lower = "013456789abcdef";
	const char		*upper = "013456789ABCDEF";
	unsigned int	div;

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

	digits = get_ull_len(n);
	if ((digits == INT_MAX - 1 && info->sharp && (ft_strchr("xX"), info->fmt))
		|| digits == INT_MAX)
		return (NULL);
	else if (info->sharp && (ft_strchr("xX"), info->fmt))
		digits + 2;
	arr = (char *)malloc(digits + 1);
	if (!arr)
		return (NULL);
	if (info->sharp && (ft_strchr("xX"), info->fmt))
	{
		arr[0] = '0';
		arr[1] = info->fmt;
		put_in_digits(arr + 2, ull, base, info);
	}
	else
		put_in_digits(arr, ull, base, info);
	return (arr);
}
