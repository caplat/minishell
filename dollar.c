#include "minishell.h"

// void replace_after_dollar(char *line, t_mini *shell)
// {
// 	t_dollar *var;

// 	var = malloc(sizeof(t_dollar));
// 	initialize_bis(*var);
// 	while(line[var->i])
// 	{
// 		var->flag = check_flag(shell);
// 		if(shell->line[var->i] == '$' && (var->flag == 0 || var->flag == 2))
// 		{
// 			var->pos = var->i;
// 			// printf("var->pos: %d\n",var->pos);
// 			printf("allo\n");
// 			var->i++;
// 			while(ft_isalnum(line[var->i]) == 1 || line[var->i] == '_')
// 			{	
// 				var->i++;
//             	var->length++;
// 			}
// 			var->compare = compare_character(var,shell);
// 			if(compare_with_env(var->compare,shell) == 1)
// 			{
// 				printf("ok\n");
// 				while(shell->command[1][var->j])
// 					shell->add_char = add_char(shell->add_char,shell->command[1][var->j++]);
// 				free(var->compare);
// 			}
// 		}
// 		shell->add_char = add_char(shell->add_char,shell->line[var->i]);
// 		var->i++;
// 	}
    
// 	printf("%s\n",shell->add_char);
// }

char *compare_character(t_dollar *var,t_mini *shell)
{
	char *compare;
	int i;

	i = 0;
	compare = malloc(sizeof(t_dollar) * var->length);
	while(i < var->length)
	{
		compare[i] = shell->line[var->pos + 1];
		i++;
		var->pos++;
	}
	printf("compare: %s\n", compare);
	return(compare);
}

void initialize_bis(t_dollar var)
{
	var.flag = 0;
	var.i = 0;
	var.j = 0;
	var.length = 0;
	var.pos = 0;
	var.compare = NULL;

}
int check_flag(t_mini *shell,int i)
{
	int flag;

	flag = 0;
	if(shell->line[i] == '\"' && flag == 0)
		flag = 2;
	if(shell->line[i] == '\"' && flag == 2)
		flag = 0;
	if(shell->line[i] == '\'' && flag == 0)
		flag = 1;
	if(shell->line[i] == '\'' && flag == 1)
		flag = 0;
	i++;
	return(flag);
}


int compare_with_env(char *compare, t_mini *shell)
{
	int i;

	i = 0;
	while(shell->env[i])
	{
		shell->command = ft_split(shell->env[i],'=');
		shell->length_command = ft_strlen(shell->command[0]);
		if(ft_strncmp(compare, shell->command[0],shell->length_command + 1) == 0)
			return(1);
		else
		{	
			free(shell->command);
			i++;
		}
	}
	return(0);
}
char *add_char(char *str,char c)
{
	char *newstr;
	int i;

	i = 0;
	newstr = ft_calloc(ft_strlen(str) + 2,sizeof(char));
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	free(str);
	return(newstr);
}

void replace_line(char *line,t_mini *shell)
{
	int i;
	int j;
	int flag;
	char *compare;
	
	i = 0;
	j = 0;
	flag = 0;
	while(line[i])
	{
		flag = check_flag(shell,i);
		shell->add_char = add_char(shell->add_char,line[i]);
		if(line[i] == '$' && (flag == 0 || flag == 2))
		{
			compare = compare_with_envbis(shell->line,i);
			if(compare_with_env(compare,shell) == 1)
			{	
				while(shell->command[1][j])
				{	
					shell->add_char = add_char(shell->add_char,shell->command[1][j++]);
					i += ft_strlen(shell->command[0]);
				}
			}
		}
		i++;
	}
}
char *compare_with_envbis(char *line,int i)
{
	int length;
	int j;
	int pos;
	char *compare;

	length = 0;
	pos = i;
	j = 0;
	while(ft_isalnum(line[i]) == 1 || line[i] == '_')
	{
		length++;
		i++;
	}
	compare = malloc(sizeof(char) * length);
	while(j < length)
	{
		compare[j] = line[pos + 1];
		j++;
		pos++;
	}
	printf("COMPARE  %s\n",compare);
	return(compare);
}