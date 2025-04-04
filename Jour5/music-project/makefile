# Executable
NAME = music

# Compiler
CC = gcc

# Flags 
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

# Liste of source files
SRC = main.c \
      src/parser.c \
      src/list.c \
      src/utils.c \
      src/display.c

# Files objets
OBJ = $(SRC:.c=.o)

# Rules by default
all: $(NAME)

# Compilation of executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Remove files .o
clean:
	rm -f $(OBJ)

# Remove .o files and executable
fclean: clean
	rm -f $(NAME)

# Compile and run the program
run: all
	./$(NAME) data.txt artist

.PHONY: all clean fclean run
