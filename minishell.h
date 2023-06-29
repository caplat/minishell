/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:08:58 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/28 12:37:51 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_lex
{
	char			*str;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

typedef struct s_mini
{
	char			**env;
	char			*line;
	char			*newline;
	char			*add_char;
	int				flag;
	char			**command;
	int				length_command;
	char			**simple_command;
	t_lex			*args;
	char			**arg_bis;
	char			**allpath;
	char			*exe;
	int				stdout_cpy;
	int				stdin_cpy;
	int				flag_redir_out;
	int				flag_redir_in;
}					t_mini;

typedef struct s_elem
{
	char			data;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct s_compteur
{
	int				i;
	int				j;
	int				length;
}					t_compteur;

// Main

void				minishell_loop(t_mini *shell);

// Linked_list

void				add_element(t_elem **head, char data);
void				printlist(t_elem *head);
t_elem				*create_elem(char data);
void				insert_after(t_elem *lst, char newdata);
void				processlist(t_elem *head, char targetchar, char newdata);
void				processlist_chevron(t_elem *head, char targetchar,
						char newdata);
char				*convert_to_str(t_elem *head);
void				free_list(t_elem *head);

// Parsing

int					count_quotes(char *line);
int					find_matching_quote(char *line, int i, int *nb_del,
						int del);
t_elem				*get_my_list(t_mini *shell);
void				separate_command(t_elem *lst, t_mini *shell);

// Utils

void				initialize(char **env, t_mini *shell);
void				maj_to_min(char *str);
char				*add_char(char *str, char c);
int					find_length(char **str);

// Exec

void				get_my_path(t_mini *shell);
int					verify(t_mini *shell, int j);
int					execute(t_mini *shell);
void				exec_all(t_mini *shell, int i);
t_lex				*find_node(int i, t_mini *shell);

//dollar

void				replace_line(char *line, t_mini *shell);
void				set_flag(char *line, t_mini *shell, int i);
char				*compare_line(char *line, int i);
int					compare_with_env(char *compare, t_mini *shell);

// Pipe

int					get_nb_node(t_lex *head);
void				do_the_pipe(t_mini *shell);

// Lexer

void				add_element_bis(t_lex **head, char *simple_command);
t_lex				*get_my_element(t_mini *shell);
t_lex				*set_command(t_lex *head);
void				printlist_bis(t_lex *head);
void				free_list_bis(t_lex *head);
void				suppr_chevron(t_lex *current);

// Signal

void				handle_SIGINT(int signal);
void				handle_SIGQUIT(int signal);
void				do_signal(void);

// Builtins

void				check_built_in(t_lex *current);

//Echo

void				echo(char **compare);
int					check_n(char **compare);

//Redirection

void				redir_output(char *filename,t_mini *shell);
void				redir_input(char *filename,t_mini *shell);
t_lex				*curate_list(t_lex *simple_command,t_mini *shell);

#endif