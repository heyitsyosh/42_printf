/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:29:03 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/02 07:41:03 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include <limits.h> //INT_MAX
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == NULL)
		return ;
	s_len = ft_strlen(s);
	while (s_len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		s += INT_MAX;
		s_len -= INT_MAX;
	}
	write(fd, s, s_len);
}
