/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:48:36 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/28 12:28:34 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initialize(char **env,t_mini *shell)
{
	shell->env = env;
	shell->line = NULL;
	shell->newline = NULL;
	shell->add_char = ft_calloc(1,2);
	shell->flag = 0;
	shell->command = NULL;
	shell->length_command = 0;
	shell->simple_command = NULL;
	shell->arg_bis = NULL;
	shell->allpath = NULL;
	shell->exe = NULL;
	shell->stdout_cpy = dup(STDOUT_FILENO);
	shell->stdin_cpy = dup(STDIN_FILENO);
	shell->flag_redir_in = 0;
	shell->flag_redir_out = 0;
}
void maj_to_min(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
			i++;
		}
		else
			i++;
	}
}
char *add_char(char *str,char c)
{
	char *newstr;
	int i;

	i = 0;
	newstr = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	free(str);
	return(newstr);
}
int find_length(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
