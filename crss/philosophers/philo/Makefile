# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/04/24 21:05:34 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philosophers

INC := include

SRC := src

OUTPUT := output

SOURCES := main.c \
	check_args.c \
	philosophers.c 

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

#############DEBUGGING  RULES#####################

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

$(OUTPUT)/%.o: $(SRC)/%.c 
	@$(CC) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

all: 
	@mkdir -p $(OUTPUT)
	@make $(NAME)

$(NAME): $(OBJ_O)
	@$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) -o $(NAME)

# -f ignores if file does not exist
clean:
	rm -rf $(OUTPUT)

fclean: clean
	@printf "Deleting binary: $(NAME)\n"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
