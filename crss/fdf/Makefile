# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 08:58:47 by ivmirand          #+#    #+#              #
#    Updated: 2025/03/08 08:59:33 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= FDF
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include/$(LIBMLX)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
		@rm -rf $(OBJS)
			@rm -rf $(LIBMLX)/build

fclean: clean
		@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
