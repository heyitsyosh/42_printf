/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/19 07:21:14 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *lltoa(, int	base)
{
	
}

char *u_itoa(unsigned int, int base)
{
	
}

int	(va_list args, t_info *info)
{
	size_t			arg_len;
	int				printed;
	unsigned int	u;
	int				di;

	printed = 0;
	if (info->fmt == 'u')
		u = va_args(args, unsigned int);
	else if (info->fmt == 'd' || info->fmt == 'i')
		di = va_args(args, int);
	num_as_arr = i_u_toa_base();
}
