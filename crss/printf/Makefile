NAME := libftprintf.a

HEADER := libftprintf.h

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
	# $(NORME)
	cd libft && make $(LIBFT)
	@make $(NAME)

clean:
	rm -rf output/*.o

# -f ignores if file does not exist
fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

test:
	cc $(CCFLAGS) main.c -I $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
