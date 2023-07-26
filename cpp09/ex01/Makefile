NAME = RPN
SRC += main.cpp RPN.cpp
OBJ += $(SRC:%.cpp=%.o)

CC = g++ -std=c++98
CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	@mkdir -p OBJ
	@mv *.o OBJ

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

src: clean all

clean:
	rm -rf $(OBJ)
	rm -rf OBJ

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re