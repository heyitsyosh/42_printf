/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:29 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/09 23:26:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_str(char *s, int fd, size_t s_len)
{
	while (s_len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		s += INT_MAX;
		s_len -= INT_MAX;
	}
	write(fd, s, s_len);
}

size_t	no_conversion(char *input)
{
	char	*percent_ptr;
	size_t	len;

	percent_ptr = ft_strchr(input, '%');
	if (!percent_ptr)
	{
		len = ft_strlen(input);
		print_str(input, 1, len);
		return (len);
	}
	else
		print_str(input, 1, percent_ptr - input);
	return (percent_ptr - input);
}
