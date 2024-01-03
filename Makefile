##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make cat
##

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES = src/script_loader.c

O_FILES = $(C_FILES:.c=.o)

NAME=my_radar

$(NAME): lib/libmy.a $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) src/$(NAME).c $(O_FILES) lib/libmy.a \
		-lcsfml-graphics -lcsfml-audio -lcsfml-system

all: $(NAME)

clean:
	make -C lib/my clean
	rm -f $(O_FILES) test_$(NAME)

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

lib/libmy.a:
	make -C lib/my

re: fclean all

.PHONY: all clean fclean re lib/libmy.a
