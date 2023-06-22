/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:58:48 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/22 19:41:34 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void exec_builtin(t_mini *shell)
// {
//     if((ft_strncmp(shell->simple_command[0], "echo", 5) == 0))
//     {
//         echo(shell->simple_command);
//     }
//     // else if(!(strcmp(shell->command[0], "cd")))
//     // {
//     //     cd(&shell->line);
//     //     printf("hello from cd");
//     // }
//     else
//     printf("Heyy from exec builtin\n");
// }

void check_built_in(t_lex *current)
{
    char **compare;

        compare = ft_split(current->str,' ');
        if(ft_strncmp(compare[0],"echo",5) == 0)
        {
            printf("built_in\n");
            echo(compare);
            free(compare);
        }
        exit(0);
}
void echo(char **compare)
{
    int i;
    int flag;
  
    if(!compare[1])
        printf("\n");
    i = check_n(compare);
    flag = i;
    printf("check_n--->%d\n",i);
    printf("compare-->%s\n",compare[i]);
    while(compare[i])
    {
        if(i >= 1)
        {
            ft_putstr_fd(compare[i],1);
            ft_putchar_fd(' ',1);
            i++;
        }
    }
    if(flag == 1)
        ft_putchar_fd('\n',1);
}
int check_n(char **compare)
{
    int i;
    int j;

    i = 0;
    while(compare[++i])
    {
        j = 0;
        if(compare[i][j++] == '-' && compare[i][j] && compare[i][j] == 'n')
        {
            while(compare[i][j] == 'n')
                j++;
            if(compare[i][j] && compare[i][j] != 'n')
                return(1);
        }
        else
            return i;
    }
    return(i);
}