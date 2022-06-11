/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:36:51 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 13:07:51 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "exec.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

static int	wait_children(pid_t last_pid, int cmd_size)
{
	int		res;
	int		status;
	pid_t	pid;

	res = 1;
	while (cmd_size--)
	{
		pid = wait(&status);
		if (pid == last_pid)
		{
			if ((status & 0xff) == 0)
				res = (status >> 8) & 0xff;
			else
				res = (status & 0xff) + 128;
		}
	}
	return (res);
}

static int	run_external_cmd(t_list *cmd_list, int redirect_fd[2], char *envp[])
{
	t_list	*head;
	t_cmd	*cmd;
	int		prev_input;
	pid_t	last_pid;

	prev_input = redirect_fd[0];
	head = cmd_list;
	while (cmd_list)
	{
		cmd = cmd_list->content;
		if (cmd_list->next)
		{
			if (pipe(cmd->fd) == -1)
				exit(errno);
		}
		else
			cmd->fd[1] = redirect_fd[1];
		last_pid = exec(cmd, prev_input, envp);
		prev_input = cmd->fd[0];
		cmd_list = cmd_list->next;
	}
	ft_lstclear(&head, free_cmd);
	return (last_pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		res;
	int		cmd_size;
	int		redirect_fd[2];
	t_list	*cmd_list;

	if (argc < 5)
		return (1);
	redirect_fd[0] = open(argv[1], O_RDONLY);
	redirect_fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (redirect_fd[0] == -1 || redirect_fd[1] == -1)
		return (1);
	cmd_list = parse_cmd(argc, argv, envp);
	cmd_size = ft_lstsize(cmd_list);
	res = run_external_cmd(cmd_list, redirect_fd, envp);
	res = wait_children(res, cmd_size);
	return (res);
}
