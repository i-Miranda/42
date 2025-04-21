# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/03/10 18:26:39 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft

COMPILER := cc

LIBFT_H := include/libft.h

GNL_H := include/get_next_line.h

PRINTF_H := include/ft_printf.h

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

GNL_SOURCES := get_next_line.c \
	get_next_line_utils.c

PRINTF_SOURCES := ft_printf.c \
	print_nums.c \
	print_text.c 

OUTPUT := src/output

LIBFT_OUTPUT := $(OUTPUT)/libft

GNL_OUTPUT := $(OUTPUT)/gnl

PRINTF_OUTPUT := $(OUTPUT)/printf

LIBFT_O := $(patsubst %.c, $(LIBFT_OUTPUT)/%.o, $(LIBFT_SOURCES))

GNL_O := $(patsubst %.c, $(GNL_OUTPUT)/%.o, $(GNL_SOURCES))

PRINTF_O := $(patsubst %.c, $(PRINTF_OUTPUT)/%.o, $(PRINTF_SOURCES))

##############DEBUGGING  RULES#####################

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

##################################################

$(LIBFT_OUTPUT)/%.o: src/libft/%.c $(LIBFT_H)
	@mkdir -p $(OUTPUT) $(LIBFT_OUTPUT)
	@$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -Iinclude/ && printf "Compiling: $(notdir $<)                                                         \r"

$(GNL_OUTPUT)/%.o: src/gnl/%.c $(GNL_H)
	@mkdir -p $(OUTPUT) $(GNL_OUTPUT)
	@$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -Iinclude/ && printf "Compiling: $(notdir $<)                                                         \r"

$(PRINTF_OUTPUT)/%.o: src/printf/%.c $(PRINTF_H)
	@mkdir -p $(OUTPUT) $(PRINTF_OUTPUT)
	@$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -Iinclude/ && printf "Compiling: $(notdir $<)                                                         \r"

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(MKDIR) $(LIBFT_O) $(GNL_O) $(PRINTF_O)
	@printf "Compilation successful: libft.a base objs\n"
	@printf "Compilation successful: libft.a gnl objs\n"
	@printf "Compilation successful: libft.a printf objs\n"
	@printf "Linking static library: $(NAME).a\n"
	@ar $(ARFLAGS) $(NAME).a $(LIBFT_O) $(GNL_O) $(PRINTF_O)
	@printf "Static library build successful: $(NAME).a\n"

all: $(NAME) 

clean:
	@printf "Wiping objs: $(NAME).a\n"
	@rm -rf $(OUTPUT)

# -f ignores if file does not exist
fclean: clean
	@printf "Deleting static library: $(NAME).a\n"
	@rm -f $(NAME).a

re: fclean all

.PHONY: all clean fclean re 
