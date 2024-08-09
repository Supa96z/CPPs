NAME = main

SOURCES = main.cpp\

OBJECTS = $(SOURCES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

$(NAME) : $(OBJECTS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
