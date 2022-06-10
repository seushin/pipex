/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:37:04 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 02:37:05 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	**split_env_value(const char *pathEnv, const char c)
{
	char	**res;
	char	*findEqSign;

	findEqSign = ft_strchr(pathEnv, '=');
	if (findEqSign == NULL)
		return (NULL);
	if (*(++findEqSign) == '\0')
		return (NULL);
	res = ft_split(findEqSign, c);
	return (res);
}

static char	**parse_env_path(char **envp, const char *env)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], env, ft_strlen(env)) == 0)
			return (split_env_value(envp[i], ':'));
		i++;
	}
	return (NULL);
}

static char	*join_path(const char *dir, const char *filename)
{
	const char	*tmp[4] = {dir, "/", filename, NULL};
	char		*path;

	path = ft_strreduce(tmp);
	return (path);
}

static char	*parse_pathname(char *filename, char *envp[])
{
	char	*res;
	char	**paths;
	int		i;

	if (filename == NULL)
		return (NULL);
	if (filename[0] == '/' || filename[0] == '.')
		return (ft_strdup(filename));
	paths = parse_env_path(envp, "PATH");
	if (paths == NULL)
		return (NULL);
	res = NULL;
	i = 0;
	while (paths[i])
	{
		res = join_path(paths[i], filename);
		if (access(res, F_OK) == 0)
			break ;
		free(res);
		res = NULL;
		i++;
	}
	ft_free_strs(paths);
	return (res);
}

char	**parse_token(char *command, char *envp[])
{
	char	**token;
	char	*pathname;

	if (command == NULL)
		return (NULL);
	token = ft_split(command, ' ');
	if (token == NULL)
		return (NULL);
	pathname = parse_pathname(token[0], envp);
	if (pathname)
	{
		free(token[0]);
		token[0] = pathname;
	}
	return (token);
}
