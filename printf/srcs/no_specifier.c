/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:29 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/10 19:40:00 by myoshika         ###   ########.fr       */
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
		len = ft_strlen(input);
	else
		len = percent_ptr - input;
	print_str(input, 1, len);
	return (len);
}
