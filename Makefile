SRC = get_next_line.c get_next_line_utils.c
SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
NAME = libgnl.a


all: $(NAME)

$(NAME): $(OBJ)
	ar -r $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	ar -r $(NAME) $?

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
