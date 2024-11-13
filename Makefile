NAME = pipex
LIBFT_PATH = mainlibft/
LIBFT = $(LIBFT_PATH)libft.a
CC = gcc
RM = rm -f
MKDIR = mkdir -p
FSANI = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror #${FSANI}

SRC = pipex.c pipex_utils.c \

SRCS_DIR = srcs/
INC_DIR = inc
OBJS_DIR = objs/

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "\033[33m--PS Compiled--\033[0m"

all: $(NAME)

fsani: CFLAGS += $(FSANI)
fsani: re

$(LIBFT):
	@make -C $(LIBFT_PATH)

bonus: all

clean:
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "\033[33m--PS Cleaned--\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re fsani