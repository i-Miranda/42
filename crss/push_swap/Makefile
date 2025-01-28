# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/01/28 15:38:31 by ivmirand         ###   ########.fr        #
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

LIBFT := libft/libft.a

SOURCES := main.c \
	push.c \
	push_swap.c \
	push_swap_utils.c \
	reverse_rotate.c \
	rotate.c \
	swap.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

#############DEBUGGING  RULES#####################

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

$(OUTPUT)/%.o: $(SRC)/%.c $(HEADER)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I$(INC) -Ilibft/$(INC)

# -r replaces or adds a file if doesn't already exisj in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBFT)-o $(NAME)

all: 
	cd libft && make all
	mkdir -p $(OUTPUT)
	make $(NAME)

# -f ignores if file does not exist
clean:
	rm -f $(NAME)
	rm -rf $(OUTPUT)
	rm -f $(LIBFT)

fclean: clean
	cd libft && $(MAKE) $@

re: fclean all

.PHONY: all clean fclean re 
