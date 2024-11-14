NAME := libftprintf.a

HEADER := ft_printf.h

LIBFT := libft.a

NORME := norminette

COMPILER := cc

SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c \
	printf_utils.c 

OBJ_O := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(COMPILER) $(CCFLAGS) -c $< -o output/$@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently 
# -s writes object-files 
ARFLAGS := -rcs

$(NAME): $(OBJ_O) $(HEADER) 
	ar $(ARFLAGS) $(NAME) output/*.o

all: 
	cd libft && make $(LIBFT)
	@make $(NAME)

clean:
	rm -rf output/*.o

# -f ignores if file does not exist
fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

testFlags:
	$(COMPILER) $(CCFLAGS) main.c $(NAME) libft/$(LIBFT)

test:
	$(COMPILER) main.c $(NAME) libft/$(LIBFT)

debug:
	$(COMPILER) -fsanitize=address -g main.c $(NAME) libft/$(LIBFT)

run:
	./a.out test

dev: fclean debug run

re: fclean all

.PHONY: all clean fclean re
