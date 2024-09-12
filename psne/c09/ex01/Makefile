NAME := libft.a

SOURCES := srcs/ft_putchar.c \
		   ft_swap.c \
		   ft_putstr.c \
		   ft_strlen.c \
		   ft_strcmp.c \

DEPS := includes/ft.h

%.o: %.c $(DEPS)
	cc $(CCFLAGS) -c $< -o $@

CCFLAGS := -Wall -Werror -Wextra

ARFLAGS := -rs

OBJS := $(SOURCES:.c=.o)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
