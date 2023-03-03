SRCS			= pipex.c get_first_file.c messeg_err.c free_ret.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= pipex

LIBFT_PATH      = ./libft
LIBFT			= -lft

all:			$(NAME) Makefile

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) $(LIBFT) -o $(NAME)

$(LIBFT):
				make -C $(LIBFT_PATH) all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJS)

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
