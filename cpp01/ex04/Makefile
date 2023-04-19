NAME = sed
SRC = main.cpp
CC = g++
CC_FLAGS = -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CC_FLAGS) $(SRC) -o $(NAME)

clean: fclean

fclean:
	rm -rf $(NAME)

re: fclean all