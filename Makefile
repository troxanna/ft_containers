

NAME = ft_containers
CPP_FILE = main.cpp 
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC_FILE = Vector/vector.hpp Map/map.hpp Stack/Stack.hpp utils/utils.hpp utils/Tree.hpp utils/MapIterator.hpp utils/Iterator.hpp 

all: $(NAME)

$(NAME): $(CPP_FILE)
	c++ $(CFLAGS) -o $(NAME) $(CPP_FILE)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re