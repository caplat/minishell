/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:10:51 by acaplat           #+#    #+#             */
/*   Updated: 2023/06/22 12:42:42:32 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void echo(char **simple_command)
// {
//     int flag;
//     int i;

//     i = 1;
//     flag = 0;
//     if(simple_command[1] && ft_strncmp(simple_command[1], "-n", 3) == 0)
//     {
//         flag = 1;
//         i = 2;
//     }
//     while (simple_command[i])
//     {
//         printf("%s ", simple_command[i]);
//         i++;
//     }
//     if(flag == 0)
//         printf("\n");
// }

// size_t check_n(char **simple_command)
// {
//     size_t i;
//     size_t j;

//     i = 0;
// 	while(simple_command[i++])
//     {
//         j = 0;
//         if(simple_command[i][j++] == '-' && simple_command[i][j] == 'n')
//         {
//             while(simple_command[i][j] == 'n')
//                 j++;
//             if(simple_command[i][j] != 'n')
//                 return 1;
//         }
//         else
//             return i;
//     }
//     return i;
// }


// int echo_bis(char **simple_command)
// {
//     size_t i;
//     int n;

//     n = 1;
	
    
// 	printf("simple-command:%s\n",simple_command[1]);
//     if(!simple_command[1])
// 	{
// 		printf("\n");
// 		return(1);
// 	}
//     if((strcmp(simple_command[1], " ") && !simple_command[2]))
//     {
// 		printf("allo\n");
//         printf("\n");
// 		return(1);
//     }
//     i = check_n(simple_command);
//     n = i > 1 ? 0 : 1;
//     printf("i: %zu\n", i);
//     while(simple_command[i])
//     {
//         printf("--->hhhh:%s\n", simple_command[i]);
//         i++;
//         if(simple_command[i])
//             printf(" ");
//     }
//     if(n)
//         printf("\n");
//     return 1;
// }