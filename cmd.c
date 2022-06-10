/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:36:55 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 02:36:57 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

t_cmd	*create_cmd(void)
{
	t_cmd	*res;

	res = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (res == NULL)
		return (NULL);
	return (res);
}

void	free_cmd(void *cmd)
{
	t_cmd	*c;

	c = cmd;
	ft_free_strs(c->token);
	free(c);
}

t_list	*parse_cmd(int argc, char *argv[], char *envp[])
{
	t_list	*res;
	t_cmd	*cmd;
	int		i;

	res = NULL;
	i = 2;
	while (i < argc - 1)
	{
		cmd = create_cmd();
		cmd->token = parse_token(argv[i++], envp);
		ft_lstadd_back(&res, ft_lstnew(cmd));
	}
	return (res);
}
