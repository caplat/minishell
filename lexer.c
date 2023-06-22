/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:35:15 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/22 18:01:59 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_element_bis(t_lex **head, char *simple_command)
{
	t_lex	*newelem;
	t_lex	*current;

	newelem = malloc(sizeof(t_lex));
	newelem->str = simple_command;
	newelem->next = NULL;
	if (*head == NULL)
	{
		newelem->prev = NULL;
		*head = newelem;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = newelem;
	newelem->prev = current;
}
void	printlist_bis(t_lex *head)
{
	t_lex	*current;

	current = head;
	while (current != NULL)
	{
		printf("printlist-->%s\n", current->str);
		current = current->next;
	}
}
void free_list_bis(t_lex *head)
{
    t_lex *current;
    t_lex *temp;

    current = head;
    while(current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
}

t_lex	*get_my_element(t_mini *shell)
{
	t_lex	*newlist;
	int		i;

	newlist = NULL;
	i = 0;
	shell->simple_command = ft_split(shell->newline, ' ');
	free(shell->newline);
	while (shell->simple_command[i])
	{
		add_element_bis(&newlist, shell->simple_command[i]);
		i++;
	}
	return (newlist);
}
t_lex	*set_command(t_lex *head)
{
	t_lex	*newlist;
	t_lex	*current;
	int		i;
	char	*test;

	i = 0;
	newlist = NULL;
	current = head;
	test = ft_calloc(1, 1);
	while (current)
	{
		test = ft_strjoin(test, current->str);
		test = ft_strjoin(test, " ");
		if (current->next && ft_strncmp(current->next->str, "|", 2) == 0)
		{
			add_element_bis(&newlist, ft_strdup(test));
			current = current->next;
			test = ft_calloc(1, 1);
		}
		current = current->next;
	}
	add_element_bis(&newlist, ft_strdup(test));
	free(test);
	return (newlist);
}
