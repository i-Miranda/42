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

COMPILER := cc

SRC := src/

MAIN := $(SRC)/main.c

BONUS := $(SRC)/bonus.c

OUTPUT := $(SRC)/output

LIBFT_OUTPUT := libft/$(OUTPUT)/

LIBFT := libft.a

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SRC))

BONUS_O := $(patsubst %.c, $(LIBFT_OUTPUT)/%.o, $(LIBFT_SOURCES))

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

$(LIBFT_OUTPUT)/%.o: src/libft/%.c $(LIBFT_HEADER)
	@mkdir -p $(OUTPUT) $(LIBFT_OUTPUT)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -I includes/

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O)
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -l$(LIBFT) -I includes/

all: $(NAME) 

clean:
	rm -rf $(LIBFT_OUTPUT) 
	rm -rf $(OBJ_O) 
	rm -rf $(BONUS_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)
	rm -rf $(OUTPUT)

re: fclean all

bonus: $(LIBFT_O) $(BONUS_O)
	ar $(ARFLAGS) $(NAME) $(LIBFT_O) $(BONUS_O)

.PHONY: all clean fclean re bonus
