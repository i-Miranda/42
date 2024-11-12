
NAME := libftprintf.a

HEADER := libftprintf.h

COMPILER := cc

SOURCES := ft_isalpha.c \

OBJ_O := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o: %.c libft.h
	$(COMPILER) $(CCFLAGS) -c $< -o $@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently 
# -s writes object-files 
ARFLAGS := -r -c -s

$(NAME): $(OBJ_O) $(HEADER) 
	ar $(ARFLAGS) $(NAME) $(OBJ_O)

all: $(NAME)

clean:
	rm -rf $(OBJ_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
