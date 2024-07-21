NAME = main

SOURCES = 	Serializer.cpp\
			main.cpp\

OBJECTS = $(SOURCES:.cpp=.o)

FLAGS = -Wall -Werror -Wextra -std=c++98

CC = c++ $(FLAGS)

$(NAME) : $(OBJECTS)
	@$(CC) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all