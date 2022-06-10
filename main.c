/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:36:51 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 03:02:30 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

static void	set_fd(t_cmd *cmd, t_list *next, char *output)
{
	if (next)
	{
		if (pipe(cmd->fd) == -1)
			exit(1);
	}
	else
	{
		cmd->fd[1] = open(output, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (cmd->fd[1] == -1)
			exit(1);
	}
}

static int	wait_children(int last_pid, pid_t cmd_size)
{
	int	res;
	int	status;

	while (cmd_size--)
	{
		if (last_pid == wait(&status))
		{
			if ((status & 0xff) == 0)
				res = (status >> 8) & 0xff;
			else
				res = (status & 0xff) + 128;
		}
	}
	return (res);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*head;
	t_list	*cmd_list;
	t_cmd	*cmd;
	int		prev_input;
	pid_t	last_pid;

	if (argc < 5)
		return (1);
	prev_input = open(argv[1], O_RDONLY);
	if (prev_input == -1)
		return (1);
	cmd_list = parse_cmd(argc, argv, envp);
	head = cmd_list;
	while (cmd_list)
	{
		cmd = cmd_list->content;
		set_fd(cmd, cmd_list->next, argv[argc - 1]);
		last_pid = exec(cmd, prev_input, envp);
		prev_input = cmd->fd[0];
		cmd_list = cmd_list->next;
	}
	ft_lstclear(&head, free_cmd);
	return (wait_children(last_pid, ft_lstsize(cmd_list)));
}
