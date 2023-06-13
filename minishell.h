/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:08:58 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/13 18:03:43 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
	int				nb_pipe;
	char			**allpath;
	char			**tab;
	char			*exe;
}					t_mini;

typedef struct s_elem
{
	char			data;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct s_lex
{
	char			*str;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

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

// Exec

void				get_my_path(t_mini *shell);
int					verify(t_mini *shell);
int					execute(t_mini *shell);
void				exec_all(t_mini *shell);

//dollar

void				replace_line(char *line, t_mini *shell);
void				set_flag(char *line, t_mini *shell, int i);
char				*compare_line(char *line, int i);
int					compare_with_env(char *compare, t_mini *shell);

// Pipe

int					create_pipe(t_mini *shell, int nb_pipe);
void				pipe_is_reading(int pipe_fd[2], int i);
void				pipe_is_writing(int new_pipe_fd[2], int i, int nb_pipe);
void				get_nb_pipe(t_lex *head, t_mini *shell);

// Lexer

void				add_element_bis(t_lex **head, char *simple_command);
t_lex				*get_my_element(t_mini *shell);
t_lex				*set_command(t_lex *head);
void				printlist_bis(t_lex *head);
void				free_list_bis(t_lex *head);

#endif