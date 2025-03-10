# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:48:08 by ivmirand          #+#    #+#              #
#    Updated: 2025/03/10 10:43:39 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

INC := include

LIBFT := libft

LIBFT_A := $(LIBFT)/$(LIBFT).a

SRC := src

HEADERS := -I$(INC) -Ilibft/$(INC)

OUTPUT := $(SRC)/output

SOURCES := main.c \
	parse.c \
	push.c \
	push_swap.c \
	push_swap_utils.c \
	reverse_rotate.c \
	rotate.c \
	sort.c \
	swap.c 
	#sort_short_stack.c \

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
	@$(CC) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

all: 
	@cd libft && make all
	@mkdir -p $(OUTPUT)
	@make $(NAME)

$(NAME): $(OBJ_O)
	@$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBFT_A) -o $(NAME)

# -f ignores if file does not exist
clean:
	@printf "Wiping static libraries and their respective objs: $(LIBFT).a\n"
	@cd libft && $(MAKE) fclean
	@rm -rf $(OUTPUT)

fclean: clean
	@printf "Deleting binary: $(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
