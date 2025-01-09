# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/01/09 12:03:42 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

INC := include

MAIN := src/pipex/main.c

COMPILER := cc

SOURCES :=

OUTPUT := src/output

LIBFT_OUTPUT := libft/$(OUTPUT)/

OBJ_O := $(patsubst %.c, $(PIPEX_OUTPUT)/%.o, $(PIPEX_SOURCES))

PRINTF_O := $(patsubst %.c, $(PRINTF_OUTPUT)/%.o, $(PRINTF_SOURCES))

##############DEBUGGING  RULES#####################

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

##############DEBUGGING  RULES#####################

$(PRINTF_OUTPUT)/%.o: src/printf/%.c $(HEADER)
	@mkdir -p $(OUTPUT) $(PRINTF_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I includes/

$(LIBFT_OUTPUT)/%.o: src/libft/%.c $(LIBFT_HEADER)
	@mkdir -p $(OUTPUT) $(LIBFT_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I includes/

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(MKDIR) $(LIBFT_O) $(PRINTF_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(OBJ_O)

all: $(NAME) 

clean:
	rm -rf $(LIBFT_OUTPUT) 
	rm -rf $(OBJ_O) 
	rm -rf $(BONUS_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)
	rm -rf $(OUTPUT)
	rm -f test
	rm -rf test.dSYM

re: fclean all

bonus: $(LIBFT_O) $(BONUS_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(BONUS_O)

.PHONY: all clean fclean re bonus
