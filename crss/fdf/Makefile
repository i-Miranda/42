# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 08:58:47 by ivmirand          #+#    #+#              #
#    Updated: 2025/04/17 12:47:42 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

INC := include

LIBFT := libft

LIBFT_A := $(LIBFT)/$(LIBFT).a

LIBMLX := MLX42

LIBMLX_A := $(LIBMLX)/build/libmlx42.a

SRC := src

HEADERS	:= -I ./$(INC) -I $(LIBMLX)/$(INC) -I $(LIBMLX)/$(INC)/$(LIBMLX) -I $(LIBFT)/$(INC)

OUTPUT := $(SRC)/output

LIBS := $(LIBMLX_A) $(LIBFT_A) -ldl -lglfw -pthread -lm 
# LIBS := $(LIBMLX_A) $(LIBFT_A) -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SOURCES	:= main.c \
	fdf.c \
	input.c \
	render.c \
	parse.c \
	coord.c \
	hooks.c \
	bresenham.c \
	collision.c \
	loading.c \
	error.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))
#OBJS := ${SRCS:.c=.o}

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
	CCFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
endif

##################################################

$(OUTPUT)/%.o: $(SRC)/%.c
	@$(CC) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

all:
	@printf "Compiling: $(NAME) dependencies\n"
	@cd $(LIBFT) && make all
	@mkdir -p $(OUTPUT)
	make libmlx
	@make $(NAME)

libmlx:
	git clone git@github.com:codam-coding-college/MLX42.git
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_O)
	@printf "Compiling: $(NAME)\n"
	@$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compilation complete: $(NAME)\n"

clean:
	rm -rf $(OUTPUT)
	rm -rf $(LIBMLX)/build
	rm -rf $(LIBFT)/src/output

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBMLX)
	rm -rf $(LIBFT_A)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
