/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:29 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/12 02:41:04 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long	no_conversion(char *input, t_printinfo *info)
{
	char	*percent_ptr;
	size_t	print_len;
	size_t	len;

	percent_ptr = ft_strchr(input, '%');
	len = ft_strlen(input);
	if (input + INT_MAX <= percent_ptr || (!percent_ptr && INT_MAX <= len))
	{
		info->error = true;
		print_len = 0;
		info->i += percent_ptr - input;
	}
	else if (!percent_ptr)
		print_len = len;
	else
		print_len = percent_ptr - input;
	write(1, input, print_len);
	info->i += print_len;
	return (print_len);
}

//check literal strings bigger than intmax