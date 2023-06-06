/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:45:00 by acaplat           #+#    #+#             */
/*   Updated: 2023/05/24 14:33:48 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_my_path(t_mini *shell)
{
	int i;
	(void)shell;

	i = 0;
	while(shell->env[i])
	{
		if (ft_strncmp("PATH", shell->env[i], 4) == 0)
		{
			shell->allpath = ft_split(ft_substr(shell->env[i], 5,
				ft_strlen(shell->env[i]) - 5), ':');
			i++;
		}
		else
			i++;
	}
}
int verify(t_mini *shell)
{
	int i;
	char *path_part;

	i = 0;
	maj_to_min(shell->tab[0]);
	while(shell->allpath[i++])
	{
		path_part = ft_strjoin(shell->allpath[i],"/");
		shell->exe = ft_strjoin(path_part,shell->tab[0]);
		free(path_part);
		if(access(shell->exe,F_OK | X_OK) == 0)
			return(1);
	}
	exit(printf("problem with verify\n"));
}
int execute(t_mini *shell)
{
	int child;

	{
		child = fork();
		if(child < 0)
			return(printf("problem with fork\n"));
		if(child == 0)
		{
			if(execve(shell->exe,shell->tab,shell->env) == -1)
				exit(printf("problem with execve\n"));
		}
		else
			waitpid(child, NULL, 0);
	}
	return(0);
}
void exec_all(t_mini *shell)
{
	get_my_path(shell);
	verify(shell);
	execute(shell);
}