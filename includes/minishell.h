#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "structure.h"

typedef struct	s_flag
{
	bool	quote;
	bool	pipe;
	bool	redir;
	bool	env_var;
}	t_flag;

typedef enum	e_def
{
	WORD,
	INPUT,
	OUTPUT,
	PIPE,
	ENV_VAR, 
	QUOTE,	
}	t_def;

char **ms_split(char *str, char c);
bool	check_space(char c);

bool	print_error(t_flag flag);
void    set_flags(char *input);
void    handle_redirection(char *input, t_flag *flag, size_t *i, char n);
void 	handle_quotes(char *input, t_flag *flag, size_t *i, char n);
void    handle_pipes(char *input, t_flag *flag, size_t *i);

#endif
