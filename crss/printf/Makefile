NAME := libftprintf.a

HEADER := includes/ft_printf.h

LIBFT := libft.a

COMPILER := cc

SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c \
	printf_utils.c

BONUS := ft_printf_bonus.c \
	print_nums_bonus.c \
	print_text_bonus.c \
	printf_utils_bonus.c

OBJ_O := $(SOURCES:.c=.o)

BONUS_O := $(BONUS:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o: src/printf/%.c $(HEADER)
	mkdir -p output
	mkdir -p output/printf
	$(COMPILER) $(CCFLAGS) -c $< -o output/printf/$@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O) $(HEADER)
	ar $(ARFLAGS) $(NAME) output/*/*.o

all:
	mkdir -p output
	mkdir -p output/libft
	mkdir -p output/printf
	cd src/libft && make $(LIBFT)
	@make $(NAME)

clean:
	rm -rf output/printf/*.o

# -f ignores if file does not exist
fclean: clean
	cd src/libft && make fclean
	rm -f $(NAME)
	rm -f test

testFlags:
	$(COMPILER) $(CCFLAGS) src/printf/main.c $(NAME) src/libft/$(LIBFT) -o test

test:
	$(COMPILER) src/printf/main.c $(NAME) src/libft/$(LIBFT) -o test

debug:
	$(COMPILER) -fsanitize=address -g src/printf/main.c $(NAME) src/libft/$(LIBFT) -o test

run:
	./test "this string is a test"

dev: fclean debug run

re: fclean all

# bonus: $(BONUS_O) $(HEADER)

.PHONY: all clean fclean re bonus
