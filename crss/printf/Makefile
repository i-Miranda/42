# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2024/12/12 20:34:47 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

HEADER := includes/ft_printf.h

BONUS_HEADER := includes/ft_printf_bonus.h

LIBFT_HEADER := includes/libft.h

MAIN := src/printf/main.c

COMPILER := cc

LIBFT_SOURCES := ft_isdigit.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_strchr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_substr.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c 

SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c 

BONUS := ft_printf_bonus.c \
	print_padding_bonus.c \
	print_nums.c \
	print_nums_bonus.c \
	print_text.c \
	print_text_bonus.c \
	process_flags_bonus.c

OUTPUT := src/output

PRINTF_OUTPUT := $(OUTPUT)/printf

LIBFT_OUTPUT := $(OUTPUT)/libft


OBJ_O := $(patsubst %.c, $(PRINTF_OUTPUT)/%.o, $(SOURCES))

BONUS_O := $(patsubst %.c, $(PRINTF_OUTPUT)/%.o, $(BONUS))

LIBFT_O := $(patsubst %.c, $(LIBFT_OUTPUT)/%.o, $(LIBFT_SOURCES))

DEBUG ?= 1

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

$(PRINTF_OUTPUT)/%.o: src/printf/%.c $(HEADER)
	@mkdir -p $(OUTPUT) $(PRINTF_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ 

$(PRINTF_OUTPUT)/%.o: src/printf/bonus/%.c $(BONUS_HEADER)
	@mkdir -p $(OUTPUT) $(PRINTF_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@

$(LIBFT_OUTPUT)/%.o: src/libft/%.c $(LIBFT_HEADER)
	@mkdir -p $(OUTPUT) $(LIBFT_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(MKDIR) $(LIBFT_O) $(OBJ_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(OBJ_O)

all: $(NAME) 

clean:
	rm -rf $(LIBFT_O) 
	rm -rf $(OBJ_O) 
	rm -rf $(BONUS_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)
	rm -rf $(OUTPUT)
	rm -f test
	rm -rf test.dSYM

testFlags:
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) $(MAIN) $(NAME) -o test

test:
	$(COMPILER) $(DBFLAGS) $(MAIN) $(NAME) -o test

run:
	./test "this string is a test"

re: fclean all

bonus: $(LIBFT_O) $(BONUS_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(BONUS_O)

.PHONY: all clean fclean re bonus
