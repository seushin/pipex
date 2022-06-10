/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:03:36 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 02:37:59 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strreduce(const char **strs)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (strs[i])
		len += ft_strlen(strs[i++]);
	len++;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (strs[i])
		ft_strlcat(res, strs[i++], len);
	return (res);
}
