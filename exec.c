/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:36:58 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 13:01:05 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int	dup_pipe(int in, int out)
{
	if (in)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
	return (0);
}

int	exec(t_cmd *cmd, int input_fd, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		dup_pipe(input_fd, cmd->fd[1]);
		if (cmd->fd[0])
			close(cmd->fd[0]);
		execve(cmd->token[0], cmd->token, envp);
		perror("execve: command not found");
		exit(errno);
	}
	else
	{
		close(input_fd);
		if (cmd->fd[1])
			close(cmd->fd[1]);
	}
	return (pid);
}
