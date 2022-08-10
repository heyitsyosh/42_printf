/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:20:32 by myoshika          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/24 11:52:43 by myoshika         ###   ########.fr       */
=======
/*   Updated: 2022/07/20 17:10:43 by myoshika         ###   ########.fr       */
>>>>>>> ba5d84c1a1cc01a6a339d3c9a2e92f711d66e013
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (dup != NULL)
		ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
