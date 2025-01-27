# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/01/27 09:44:37 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

HEADER := include/ft_printf.h

LIBFT_HEADER := include/libft.h

COMPILER := cc

LIBFT_SOURCES := ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

PRINTF_SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c 

OUTPUT := src/output

PRINTF_OUTPUT := $(OUTPUT)/printf

LIBFT_OUTPUT := $(OUTPUT)/libft

PRINTF_O := $(patsubst %.c, $(PRINTF_OUTPUT)/%.o, $(PRINTF_SOURCES))

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
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I include/

$(PRINTF_OUTPUT)/%.o: src/printf/bonus/%.c $(BONUS_HEADER)
	@mkdir -p $(OUTPUT) $(PRINTF_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I include/

$(LIBFT_OUTPUT)/%.o: src/libft/%.c $(LIBFT_HEADER)
	@mkdir -p $(OUTPUT) $(LIBFT_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I include/

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(MKDIR) $(LIBFT_O) $(OBJ_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(OBJ_O)

all: $(NAME) 

clean:
	# rm -rf $(LIBFT_O) 
	# rm -rf $(OBJ_O) 

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)
	rm -rf $(OUTPUT)
	rm -f test
	rm -rf test.dSYM

re: fclean all

.PHONY: all clean fclean re 
