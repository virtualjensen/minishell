NAME		=		minishell

CC 			= 		cc

CFLAGS 		= 		-Wall -Werror -Wextra -Iincludes

SRCS 		=		main.c

SRCS_DIR 	= 		./srcs/

OBJS		=		$(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

LIBFT_DIR 	= 		./libft/

LIBFT 		= 		./libft/libft.a

$(NAME) 	: 		$(OBJS)
					make all -C $(LIBFT_DIR)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all 		: 		$(NAME)

clean 		:
					make clean -C $(LIBFT_DIR)
					rm -f $(OBJS)

fclean 		: 		clean
					make fclean -C $(LIBFT_DIR)
					rm -f $(NAME)

re 			: 		fclean all

.PHONY 		: 		$(NAME) all clean fclean re
