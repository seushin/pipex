/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:37:11 by seushin           #+#    #+#             */
/*   Updated: 2022/06/11 02:37:12 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "cmd.h"

char	**parse_token(char *command, char *envp[]);
int		exec(t_cmd *cmd, int input_fd, char *envp[]);

#endif // !PIPEX_H
