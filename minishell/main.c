/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis <yacis@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:11:29 by yacis             #+#    #+#             */
/*   Updated: 2022/11/11 21:58:53 by yacis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void pwd()
{
	char	cwd[1024];
	chdir("/path/to/change/directory/to");
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}

void	echo(char *str)
{
	if (str[4] == ' ' && str[5] == '-' && str[6] == 'n' && str[7] == ' ')
	{
		str += 8;
		printf("%s%%\n", str);
	}
	else if (str[4] == ' ' && str[5] == '-' && str[6] == 'n' && str[7] != '\0')
	{
		str += 5;
		printf("%s\n", str);
	}
	else if (str[4] == ' ' && str[5] == '-' && str[6] == 'n')
		return ;
	else
	{
		str += 5;
		printf("%s\n", str);
	}
}

int main(void)
{
	char	*read;

	while (1)
	{
		read = readline("minishell ~ % "); // Yürütme anında okunan her satır read değişkenine atılır.
		if (!(ft_strcmp(read, "pwd"))) // read değişkeni pwd ise pwd fonksiyonuna yönelendirir.
			pwd();
		else if (read[0] == 'e' && read[1] == 'c' && read[2] == 'h' && read[3] == 'o')
		{
			if (read[4] == '\0')
				printf("\n");
			else if (read[4] == ' ')
				echo(read);
			else 
				printf("zsh: command not found: %s\n", read);
		}
		else
			printf("zsh: command not found: %s\n", read);
		free(read);
	}
}
