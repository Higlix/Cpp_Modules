RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m


NAME = interface
INC += AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp
SRC += main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
OBJ += $(SRC:%.cpp=%.o)

CC = g++ -std=c++98
CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INC)
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