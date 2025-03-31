# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 08:58:47 by ivmirand          #+#    #+#              #
#    Updated: 2025/03/31 12:41:34 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := FDF

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
	vertex.c \
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
	CCFLAGS	:= -Wextra -Wall -Werror # -Wunreachable-code -Ofast
endif

##################################################

$(OUTPUT)/%.o: $(SRC)/%.c
	@$(CC) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

all:
	@printf "Compiling: $(NAME) dependencies\n"
	@cd $(LIBFT) && make all
	@mkdir -p $(OUTPUT)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@make $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_O)
	@printf "Compiling: $(NAME)\n"
	@$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJ_O) $(LIBS) $(HEADERS) -o $(NAME) && printf "Compilation complete: $(NAME)\n"

clean:
	@printf "Wiping static libraries and their respective objs: $(LIBFT).a and libmlx42.a\n"
	@rm -rf $(OBJ_O)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/src/output
	@rm -rf $(LIBFT_A)

fclean: clean
	@printf "Deleting binary: $(NAME)\n"
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
