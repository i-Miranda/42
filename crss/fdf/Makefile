# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 08:58:47 by ivmirand          #+#    #+#              #
#    Updated: 2025/04/20 14:32:34 by ivmirand         ###   ########.fr        #
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
	bresenham.c \
	collision.c \
	color.c \
	terminal.c

BONUS_SOURCES := main_bonus.c \
	fdf.c \
	input.c \
	render.c \
	parse.c \
	coord.c \
	bresenham.c \
	collision.c \
	color.c \
	terminal.c

OBJ_O := $(patsubst %.c, $(OUTPUT)/%.o, $(SOURCES))

BONUS_O := $(patsubst %.c, $(OUTPUT)/%.o, $(BONUS_SOURCES))

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
	CCFLAGS	:= -Wextra -Wall -Werror #-Wunreachable-code -Ofast
endif

$(shell mkdir -p $(OUTPUT))

##################################################

$(OUTPUT)/%.o: $(SRC)/%.c
	$(CC) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ $(HEADERS)

all:
	cd $(LIBFT) && make all
	make libmlx
	make $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_O)
	$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OUTPUT)
	rm -rf $(LIBMLX)/build
	rm -rf $(LIBFT)/src/output

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_A)

re: fclean all

bonus: $(BONUS_O) all
	$(CC) $(CCFLAGS) $(DBFLAGS) $(BONUS_O) $(LIBS) $(HEADERS) -o $(NAME)

.PHOY: all, clean, fclean, re, bonus
