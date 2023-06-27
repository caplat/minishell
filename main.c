/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:47 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/27 17:36:34 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_mini	*shell;

	(void)argv;
	if (argc != 1)
	{
		printf("retry without arguments\n");
		exit(0);
	}
	shell = malloc(sizeof(t_mini));
	initialize(env, shell);
	rl_catch_signals = 0;
	do_signal();
	minishell_loop(shell);
}
void	minishell_loop(t_mini *shell)
{
	t_elem	*lst;
	t_lex	*simple_command;
	t_lex	*newlist;

	while (1)
	{
		shell->line = readline(">>");
		if (shell->line != NULL && ft_strlen(shell->line) > 0)
		{
			add_history(shell->line);
			if (count_quotes(shell->line) == 1)
			{
				replace_line(shell->line, shell);
				lst = get_my_list(shell);
				separate_command(lst, shell);
				shell->newline = convert_to_str(lst);
				simple_command = get_my_element(shell);
				newlist = curate_list(simple_command);
				shell->args = set_command(newlist);
				printlist_bis(shell->args);
				do_the_pipe(shell);
				printf("ERROR\n");

			}
			free(shell->line);
			free(shell->add_char);
			// free(shell->newline);
			free_list(lst);
			shell->add_char = ft_calloc(1, 2);
		}
		else
			exit(0);
	}
}
