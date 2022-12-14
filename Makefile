NAME = minishell
CFLAGS ?= -Wall -Wextra -Werror -g
CC = gcc

HEADERFILES = includes/minishell.h

SRC_FILES = main.c prompt.c exit_message.c lexer.c \
			lexer_utils.c split_str.c print_list.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix obj/, $(OBJ_FILES))

LIB += libft/libft.a
LIB += -lreadline #-lhistory
LIBFT_DIR = libft/

all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILES)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

obj/%.o: src/%.c 
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re play