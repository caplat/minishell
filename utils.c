/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:48:36 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/06 14:47:57 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initialize(char **env,t_mini *shell)
{
	shell->env = env;
	shell->line = NULL;
	shell->newline = NULL;
	shell->add_char = ft_calloc(1,1);
	shell->command = NULL;
	shell->length_command = 0;
	shell->tab = NULL;
	shell->allpath = NULL;
	shell->exe = NULL;
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
