NAME = main

SOURCES = 	Serializer.cpp\
			main.cpp\

OBJECTS = $(SOURCES:.cpp=.o)

FLAGS = -Wall -Werror -Wextra

CC = c++

$(NAME) : $(OBJECTS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
