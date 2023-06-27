
NAME = minishell

SRCS = main.c utils.c parsing.c exec.c pipe.c linked_list.c dollar.c lexer.c signal.c \
			builtins/echo.c builtins/exec_builtins.c redirection.c

CC = gcc -Wall -Wextra -Werror -g3

# RM = rm -rf

# AR = ar rcs

# INC = -I /Users/$$USER/.brew/opt/readline/include

# LIBS = libft/libft.a #get_next_line/gnl.a

# LIB	= -lreadline -L/Users/$$USER/.brew/opt/readline/lib

# OBJS = ${SRCS:.c=.o}

# .c.o:
# 	${CC} ${INC} -g3 -c $< -o ${<:.c=.o}

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@make all -C ./libft
# #	@make all -C ./get_next_line
# 	@echo "libs compileded!"
# 	$(CC) $(OBJS) $(LIB) $(LIBS) -o $(NAME)
# 	@echo "minishell compileded!"

# new_history:
# 	$(RM) .history
# 	@touch .history

# re: fclean all

# debug: $(OBJS)
# 	@make all -C ./libft
# #	@make all -C ./get_next_line
# 	@echo "libs compileded!"
# 	$(CC) $(DEBUG) $(OBJS) $(LIB) $(LIBS) -o $(NAME)
# 	@echo "minishell_debug compileded!"

# clean:
# 	$(RM) $(OBJS)
# 	@echo "Minishell cleaned"

# fclean:
# 	$(RM) $(OBJS) $(NAME)
# 	@echo "Minishell fcleaned"

# clean_libs:
# 	@make clean -C ./libft
# #	@make clean -C ./get_next_line
# 	@echo "Librairies cleaned"

# fclean_libs:
# 	@make fclean -C ./libft
# #	@make fclean -C ./get_next_line
# 	@echo "Librairies fcleaned"

# clean_all: clean clean_libs

# fclean_all: fclean fclean_libs

# .PHONY: all clean fclean debug clean_libs fclean_libs clean_all fclean_all

MY_OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIB = -lreadline -L/Users/$$USER/.brew/opt/readline/lib

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I /Users/$$USER/.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) $(LIBFT) -o $(NAME)

debug: $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) -fsanitize=address $(LIBFT) -o $(NAME)

RM=rm -f

clean:
	$(RM) $(MY_OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C libft fclean

re:	fclean all