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

void echo(char **compare)
{
    int i;
	int j;
    int flag;
  
	if(!compare[1])
        printf("\n");
	j = find_length(compare);
    i = check_n(compare);
    flag = i;
	// printf("j--->%d\n",j);
    // printf("check_n--->%d\n",i);
    // printf("compare-->%s\n",compare[i]);
    while(compare[i])
    {
        if(i >= 1)
        {
            ft_putstr_fd(compare[i],1);
			if(i < j - 1)
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
