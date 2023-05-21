/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:47:39 by jebucoy           #+#    #+#             */
/*   Updated: 2023/05/21 18:01:00 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// false means open quote found, true means closing quote found
bool   print_error(t_flag flag)
{
    if (flag.quote == false)
        printf("syntax error: unclosed quotes\n");
    else if (flag.redir == false)
        printf("syntax error: no file included for redirection\n");
    else if (flag.pipe == false)
        printf("syntax error: pipes\n");
    return (true);
} 

void    set_flags(char *input)
{
    size_t  i;
    
    t_flag flag;
    
    i = 0;
    flag.quote = true;
    flag.redir = true;
    flag.pipe = true;
    while (input[i])
    {
        if (input[i] == '"' || input[i] == '\'')
            handle_quotes(input, &flag, &i, input[i]);
        if (input[i] == '>'  || input[i] == '<')
            handle_redirection(input, &flag, &i, input[i]);
        if (input[i] == '|')
            handle_pipes(input, &flag, &i);
        i++;
    }
    print_error(flag);
}