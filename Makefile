NAME = pipex

CC = gcc

RM = rm -f

SRC = pipex.c pipex_utils.c \

CFLAGS = -Wall -Wextra -Werror

OPTION = -I ./

OBJS = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft
	@echo "\033[92m--PS Compiled--\033[0m"

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

bonus: all

clean:
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "\033[92m--PS Cleaned--\033[0m"

MKDIR = mkdir -p

FSANI = -fsanitize=address -g3

fsani: CFLAGS += $(FSANI)
fsani: re

re: fclean all

.PHONY: all bonus clean fclean re fsani