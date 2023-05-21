#ifndef STRUCTURE_H
# define STRUCTURE_H

/**
               |-> t_minishell  minishell->cmd
               |
|- -------------------------------------------------|
 echo    hi     >     test.txt   |   cat       -e
 |____________________________|     |_____________|
  |_______|     |      |_____|       |__|  |   |_|
   |     |      |         |           |    |    |
   |     v      |         |        ___|    |    |_-> args[1]
   |    args[1] |         |       |        |
   |            |         |       v        |
   v            |         |    args[0]     |
 args[0]        |         |                v
                |         v            cmd->next;
                |    redir_out[0]
                |   redir_out_type[0] = REDIR_OUT
                v
            t_cmd *cmd;
**/

enum e_redir
{
    REDIR_IN,
    REDIR_OUT,
    APPEND,
    HEREDOC
};

typedef struct s_cmd
{
    char                    **args; // cmd && args excluding the redirections
    char                    **redir_in;
    enum e_redir            *redir_in_type;
    char                    **redir_out;
    enum e_redir            *redir_out_type;
    struct s_cmd            *next;
} t_cmd;

typedef struct s_minishell
{
    int     exit_code;
    t_cmd   *cmd;
} t_minishell;

#endif
