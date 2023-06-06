/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:09:10 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/06 17:02:57 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_quotes(char *line)
{
	int i;
	int s;
	int d;

	i = -1;
	s = 0;
	d = 0;

	while(line[++i])
	{
		if(line [i] == '\'')
			i += find_matching_quote(line,i,&s,'\'');
		if(line[i] == '\"')
			i += find_matching_quote(line,i,&d,'\"');
	}
	if((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
	{
		printf("quotes not closed\n");
		exit(0);
	}
	return(1);
}

int find_matching_quote(char *line,int i,int *nb_del,int del)
{
	int j;
	
	j = i + 1;
	*nb_del += 1;
	while(line[j] && line[j] != del)
		j++;
	if(line[j] == del)
		*nb_del += 1;
	return(j - i);
}
t_elem *get_my_list(t_mini *shell)
{
	t_elem *lst;
	int i;

	lst = NULL;
	i = 0;
	while(shell->line[i])
	{
		add_element(&lst,shell->line[i]);
		i++;
	}
	return(lst);
}
void separate_command(t_elem *lst,t_mini *shell)
{
	(void) shell;

	processlist(lst,'|',' ');
	processlist_chevron(lst,'<',' ');
	processlist_chevron(lst,'>',' ');
	printlist(lst);
}

