CC = gcc

NAME = minishell

MY_SOURCES = utils.c main.c parsing.c exec.c pipe.c linked_list.c dollar.c lexer.c signal.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIB = -lreadline 

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) -L ~/.brew/opt/readline/lib  $(LIB) $(LIBFT) -o $(NAME)

debug: $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) -L ~/.brew/opt/readline/lib -fsanitize=address $(LIB) $(LIBFT) -o $(NAME)

RM=rm -f

clean:
	$(RM) $(MY_OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C libft fclean

re:	fclean all