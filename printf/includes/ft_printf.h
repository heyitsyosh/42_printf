/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:46:50 by myoshika          #+#    #+#             */
/*   Updated: 2022/08/12 02:40:31 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_printinfo
{
	size_t	i;					
	size_t	printed;
	bool	error;			
	char	current_specifier;	
	int		precision;
	int		width;
	bool	dash;
	int		zero;
	bool	sharp;
	bool	space;
	bool	plus;
}	t_printinfo;

#endif