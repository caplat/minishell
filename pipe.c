/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:01:07 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/13 18:05:18 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_nb_pipe(t_lex *head,t_mini *shell)
{
	t_lex *current;
	int i;

	i = 0;
	current = head;
	while(current)
	{
		current = current->next;
		i++;
	}
	shell->nb_pipe = i - 1;
}

int create_pipe(t_mini *shell, int nb_pipe)
{
	(void)shell;
	int pipe_fd[2];
	int new_pipe_fd[2];
	int pid;
	int i;

	i = -1;
	while(++i < nb_pipe)
	{
		if(pipe(new_pipe_fd) == -1)
			return(1); //erreur creation pipe
		pid = fork();
		if(pid == -1)
			return(2); //erreur processus fils
		if(pid == 0)
		{
			pipe_is_reading(pipe_fd,i);
			pipe_is_writing(new_pipe_fd,i,nb_pipe);
			//execute la commande approprie pour chaque processus enfant
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		pipe_fd[0] = new_pipe_fd[0];
		pipe_fd[1] = new_pipe_fd[1]; 
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	i = -1;
	while(++i < nb_pipe)
		wait(NULL);
	return(0);
}

void pipe_is_reading(int pipe_fd[2],int i)
{
	close(pipe_fd[1]);
	if(i > 0)
	{
		dup2(pipe_fd[0],STDIN_FILENO);
		close(pipe_fd[0]);

	}
}
void pipe_is_writing(int new_pipe_fd[2],int i,int nb_pipe)
{
	close(new_pipe_fd[0]);
	if(i < nb_pipe - 1)
		dup2(new_pipe_fd[1],STDOUT_FILENO);
	close(new_pipe_fd[1]);
}

