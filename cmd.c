/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:36:55 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 13:45:41 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "parse.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

t_cmd	*create_cmd(void)
{
	t_cmd	*res;

	res = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	return (res);
}

void	free_cmd(void *cmd)
{
	t_cmd	*c;

	c = cmd;
	if (c)
		ft_free_strs(c->token);
	free(c);
}

t_list	*parse_cmd(int argc, char *argv[], char *envp[])
{
	t_list	*res;
	t_list	*new;
	t_cmd	*cmd;
	int		i;

	res = NULL;
	i = 2;
	while (i < argc - 1)
	{
		cmd = create_cmd();
		if (cmd)
			cmd->token = parse_token(argv[i++], envp);
		new = ft_lstnew(cmd);
		ft_lstadd_back(&res, new);
		if (cmd == NULL || cmd->token == NULL || new == NULL)
		{
			ft_lstclear(&res, free_cmd);
			return (NULL);
		}
	}
	return (res);
}
