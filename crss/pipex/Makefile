# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/02/17 18:06:30 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

INC := include

COMPILER := cc

SRC := src

HEADER := $(INC)/pipex.h

MAIN := $(SRC)/main.c

OUTPUT := $(SRC)/output


LIBFT := libft/libft.a

SOURCES := main.c \
	pipex.c \
	pipex_utils.c \
	pipex_errors_bash.c \
	pipex_fds.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

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

$(OUTPUT)/%.o: $(SRC)/%.c $(HEADER)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I$(INC) -Ilibft/$(INC)

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBFT) -o $(NAME)

all: 
	cd libft && make all
	mkdir -p $(OUTPUT) $(BONUS_OUTPUT)
	make $(NAME)

# -f ignores if file does not exist
clean:
	rm -rf $(NAME) 

fclean: clean
	cd libft && $(MAKE) $@
	rm -rf $(OUTPUT) $(BONUS_OUTPUT) $(LIBFT) 

re: fclean all

.PHONY: all clean fclean re 
