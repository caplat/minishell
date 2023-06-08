/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:40:56 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/08 17:46:24 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void replace_line(char *line,t_mini *shell)
{
	int i;
	int j;
	int length;
	char *compare;

	i = 0;
	j = 0;
	length = 0;
	while(line[i])
	{
		set_flag(line,shell,i);
		if(line[i] == '$' && (shell->flag == 0 || shell->flag == 2))
		{
			compare = compare_line(line,i);
			if(compare_with_env(compare,shell) == 1)
			{
				printf("allo\n");
				while(shell->command[1][j])
					shell->add_char = add_char(shell->add_char,shell->command[1][j++]);
				i += ft_strlen(shell->command[0]) + 1;
			}
		}
		shell->add_char = add_char(shell->add_char,line[i]);
		i++;
	}
	printf("-->%s\n",shell->add_char);
}
void set_flag(char *line,t_mini *shell,int i)
{
	if(line[i] == '\"' && shell->flag == 0)
		shell->flag = 2;
	else if(line[i] == '\"' && shell->flag == 2)
		shell->flag = 0;
	else if(line[i] == '\'' && shell->flag == 0)
		shell->flag = 1;
	else if(line[i] == '\'' && shell->flag == 1)
		shell->flag = 0;
	else if(line[i] == '$')
		return;
	i++;
}
char *compare_line(char *line,int i)
{
	char *compare;
	int length;
	int pos;
	int j;

	compare = NULL;
	printf("compare before%s\n",compare);
	length = 0;
	j = 0;
	i++;
	pos = i;
	printf("position->%d\n",pos);
	while(ft_isalnum(line[i]) == 1 || line[i] == '_')
	{
		i++;
		length++;
	}
	compare = malloc(sizeof(char) * length);
	while(j < length)
	{
		compare[j] = line[pos];
		printf("%c\n",compare[j]);
		j++;
		pos++;
	}
	printf("COMPARE AFTER-->%s\n",compare);
	return(compare);
}
int compare_with_env(char *compare, t_mini *shell)
{
	int i;

	i = 0;
	while(shell->env[i])
	{
		shell->command = ft_split(shell->env[i],'=');
		shell->length_command = ft_strlen(shell->command[0]);
		if(ft_strncmp(compare, shell->command[0],shell->length_command + 1) == 0)
			return(1);
		else
		{	
			free(shell->command);
			i++;
		}
	}
	return(0);
}
