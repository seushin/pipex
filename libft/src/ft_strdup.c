/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:55:23 by seushin           #+#    #+#             */
/*   Updated: 2021/11/06 00:51:39 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	size;

	size = ft_strlen(s) + 1;
	res = (char *)malloc(size);
	if (!res)
		return (0);
	ft_strlcpy(res, s, size);
	return (res);
}
