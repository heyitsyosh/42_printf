/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:37:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/17 22:15:17 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char *iu_toa_base()
// {
	
// }

int	put_int(va_list args, t_printinfo *info)
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
	arg_len = ft_strlen(num_as_arr);
	if (info->precision != -1 && info->precision < arg_len)
		arg_len = info->precision;
	if (info->dash == true)
		printed += print_str(arg, arg_len);
	while (info->width-- > arg_len)
		printed += write(1, &info->padding, 1);
	if (info->dash == false)
		printed += print_str(arg, arg_len);
	return (printed);
}
