/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:20:07 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/27 17:22:43 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redir_output(char *filename)
{
	int fd;
	fd = open(filename,O_WRONLY | O_CREAT,0777);
	dup2(fd,STDOUT_FILENO);
	close(fd);
}

void redir_input(char *filename)
{
	int fd;

	fd = open(filename,O_RDONLY);
	dup2(fd,STDIN_FILENO);
	close(fd);
}
t_lex *curate_list(t_lex *simple_command)
{
	t_lex *newlist;
	t_lex *current;

	current = simple_command;
	newlist = NULL;
	while(current)
	{
		if(ft_strncmp(current->str,">",2) == 0)
		{
			current = current->next;
			// printf("current-->%s\n",current->str);
			redir_output(current->str);
			if(current->next == NULL)
				return(newlist);
		}
		// if(ft_strncmp(current->str,">>",3) == 0)
		// 	current = current->next;
		if(ft_strncmp(current->str,"<",2) == 0)
		{	
			current = current->next;
			redir_input(current->str);
			if(current->next == NULL)
				return(newlist);
		}
		// if(ft_strncmp(current->str,"<<",3) == 0)
		// 	current = current->next;
		else
			add_element_bis(&newlist,current->str);
		current = current->next;
	}
	printlist_bis(newlist);
	return(newlist);
}