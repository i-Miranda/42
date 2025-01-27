# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/01/27 13:22:15 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

INC := include

COMPILER := cc

SRC := src

HEADER := $(INC)/push_swap.h

MAIN := $(SRC)/main.c 

OUTPUT := $(SRC)/output

LIBFT_OUTPUT := libft/$(OUTPUT)

LIBFT := libft.a

SOURCES := main.c \
	push.c \
	push_swap.c \
	push_swap_utils.c \
	reverse_rotate.c \
	rotate.c \
	swap.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

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

##################################################

$(OUTPUT)/%.o: src/%.c $(HEADER)
	@mkdir -p $(OUTPUT) 
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I include/

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(MKDIR) $(OBJ_O)
	cd libft && $(MAKE) all
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ libft/$(LIBFT) -I include/

all: $(NAME) 

# -f ignores if file does not exist
clean:
	rm -f $(NAME)
	rm -rf $(OUTPUT)

fclean: clean
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re 
