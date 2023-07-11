RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m


NAME = crat
SRC += main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp
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