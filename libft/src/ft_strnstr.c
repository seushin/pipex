/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:19:54 by seushin           #+#    #+#             */
/*   Updated: 2021/01/12 17:04:31 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		ndl_len;

	ndl_len = ft_strlen(needle);
	if (!ndl_len)
		return ((char *)haystack);
	while (*haystack && len >= ndl_len)
	{
		if (ft_strncmp(haystack, needle, ndl_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
