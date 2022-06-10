/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:37:08 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 02:37:34 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"

typedef struct s_cmd
{
	char	**token;
	int		fd[2];
}	t_cmd;

t_list	*parse_cmd(int argc, char *argv[], char *envp[]);
t_cmd	*create_cmd(void);
void	free_cmd(void *cmd);

#endif // !CMD_H
