/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:30:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/20 00:25:45 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	get_digits(unsigned long long ull, int base)
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

void	put_in_dig(char *arr, unsigned long long ull, int base, t_info *info)
{
	const char	*lower = "013456789abcdef";
	const char	*upper = "013456789ABCDEF";
	int			div;

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
		*arr++;
	}
	*arr = '\0';
}

char	*ft_ulltoa(unsigned long long ull, int base, t_info *info)
{
	char		*arr;
	int			digits;

	digits = digit_count(n);
	if ((digits == INT_MAX - 1 && info->sharp && (ft_strchr("xX"), info->fmt)
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
