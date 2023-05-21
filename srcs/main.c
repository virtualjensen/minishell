#include "minishell.h"

int main (void)
{
    char    *out;
    ft_putendl_fd("Welcome to minishell", 1);
    while(1)
    {
        out = readline("$ ");
        set_flags(out);
        if (out && *out)
            add_history(out);
    }
}
