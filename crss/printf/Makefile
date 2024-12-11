NAME := libftprintf.a

HEADER := includes/ft_printf.h

LIBFT := libft.a

COMPILER := cc

SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c 

BONUS := ft_printf_bonus.c \
	print_nums_bonus.c \
	print_text_bonus.c 

OBJ_O := $(SOURCES:.c=.o)

BONUS_O := $(BONUS:.c=.o)

PRINTF_OUTPUT := output/printf/

LIBFT_OUTPUT := output/libft/

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	DBFLAGS := -g
else ifeq ($(DEBUG), 2)
	DBFLAGS := -fsanitize=address
else ifeq ($(DEBUG), 3)
	DBFLAGS := -fsanitize=address -g
else
	DBFLAGS :=
endif

NOFLAGS ?= 0

ifeq ($(NOFLAGS), 1)
	CCFLAGS :=
	DBFLAGS :=
else 
	CCFLAGS := -Wall -Wextra -Werror
endif

%.o: src/printf/%.c $(HEADER)
	mkdir -p output $(LIBFT_OUTPUT) $(PRINTF_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $(PRINTF_OUTPUT)$@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O) $(HEADER)
	ar $(ARFLAGS) $(NAME) output/*/*.o

all:
	mkdir -p output $(LIBFT_OUTPUT) $(PRINTF_OUTPUT)
	cd src/libft && make $(LIBFT)
	@make $(NAME)

clean:
	rm -rf $(PRINTF_OUTPUT)*.o

# -f ignores if file does not exist
fclean: clean
	cd src/libft && make fclean
	rm -f $(NAME)
	rm -f test
	rm -rf output
	rm -rf test.dSYM

testFlags:
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) src/printf/main.c $(NAME) src/libft/$(LIBFT) -o test

test:
	$(COMPILER) $(DBFLAGS) src/printf/main.c $(NAME) src/libft/$(LIBFT) -o test

run:
	./test "this string is a test"

re: fclean all

#bonus: $(BONUS_O) all
#	ar $(ARFLAGS) $(NAME) output/*/*.o

.PHONY: all clean fclean re bonus
