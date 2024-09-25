NAME := libfttest

COMPILER := cc

SOURCES := test.c

LIBRARY := libft.a

OUTPUT := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o : %.c libft.h
	$(COMPILER) $< $(LIBRARY) -lbsd -o $@ 

$(NAME) : $(OUTPUT)
	./test.o

.PHONY := all, clean, fclean, re

all : $(NAME)

clean :
	rm -rf $(OUTPUT)

fclean : clean
	clear

re : fclean all 
