/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:46:50 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/11 01:13:32 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_printinfo
{
	size_t	i;
	char	current_specifier;
	int		digits;
	int		precision;
	int		width;
	bool	dash;
	int		zero;
	bool	sharp;
	bool	space;
	bool	plus;
	bool	error;
}	t_printinfo;

#endif