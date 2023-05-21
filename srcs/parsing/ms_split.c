/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:50:58 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/21 17:51:21 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*task for today
- validate commands before parsing 
- handle unclosed quotes before parsing
- tokenize each 'word' in the string before any validation/parsing
- plan out how to send arguments from the CLI to the structure
- create function to split by pipes
- create function to handle quotation marks, single and double, multiples*/



bool	check_space(char c)
{
	if ( c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	else
		return (false);
}

size_t	count_str(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i]) || (str[i + 1] == 0))
		{
			count++;
			while (str[i] == c && str[i + 1] == c)
				i++;
		}
		i++;
	}
	return (count);
}

char *ms_substr(char *str, size_t start, size_t end)
{
    size_t	i = 0;
	char *new_str;

	new_str = (char *)malloc(sizeof(char) * (end - start) + 1);
	while (str[start] && start < end)
	{
		new_str[i] = str[start];
		start++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char **ms_split(char *str, char c)
{
    char    **array;
    size_t        i;
    size_t        j;
    size_t     out;

    i = 0;
    j = 0;
    out = 0;
    array = (char **)malloc(sizeof(char *) * (count_str(str, c) + 1));
    while (str[i])
	{
		while (str[i] && check_space(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		j = i;
		while (str[j] && str[j] != c)
			j++;
		array[out] = ft_substr(str, i, j);
		out++;
        if (str[j] == '\0')
		    i = j;
        else
            i = j + 1;
	}
	array[out] = NULL;
	return (array);
}