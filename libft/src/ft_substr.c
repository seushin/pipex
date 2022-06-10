/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:18:53 by seushin           #+#    #+#             */
/*   Updated: 2021/11/06 00:11:19 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;

	if (!s)
		return (0);
	while (*s && start--)
		s++;
	str_len = ft_strlen(s);
	str_len = ft_min(str_len, len);
	res = (char *)malloc(str_len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s, str_len + 1);
	return (res);
}
