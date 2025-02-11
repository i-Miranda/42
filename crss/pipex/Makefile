# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/02/11 12:54:36 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

INC := include

COMPILER := cc

SRC := src

HEADER := $(INC)/pipex.h

MAIN := $(SRC)/main.c

OUTPUT := $(SRC)/output

BONUS_OUTPUT := $(SRC)/bonus/output

LIBFT := libft/libft.a

SOURCES := main.c \
	pipex.c \
	pipex_utils.c

BONUS_SOURCES := main_bonus.c \
	pipex_bonus.c \
	pipex_utils_bonus.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

BONUS_O := $(patsubst %.c, $(BONUS_OUTPUT)/%.o, $(BONUS_SOURCES))

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

$(BONUS_OUTPUT)/%.o: $(SRC)/bonus/%.c $(HEADER)
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

bonus: $(BONUS_O)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re bonus
