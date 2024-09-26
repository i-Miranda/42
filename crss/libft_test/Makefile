NAME := libfttest

COMPILER := cc

SOURCES := test_main.c \
	test_1.c \
	test_2.c \
	test_bonus.c \
	test_auxiliary.c \

LIBRARY := libft.a

OUTPUT := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o : %.c libft.h
	$(COMPILER) $(LIBRARY) -lbsd -c $< -o $@ 

$(NAME) : $(OUTPUT)

.PHONY := all, clean, fclean, re

all : $(NAME)
	./test.o

clean :
	rm -rf $(OUTPUT)

fclean : clean
	clear

re : fclean all 
