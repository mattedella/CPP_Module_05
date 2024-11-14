SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -f
NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "compiled $(NAME)"

%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ)
		@echo "removed object files"

fclean: clean
		@$(RM) $(NAME)
		@echo "removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re