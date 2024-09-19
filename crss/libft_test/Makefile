NAME := libfttest

COMPILER := cc

SOURCES := test.c

LIBRARY := libft.a

OUTPUT := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o : %.c libft.h
	$(COMPILER) $< $(LIBRARY) -o $@ 

$(NAME) : $(OUTPUT)
	./test.o

.PHONY := all, clean, fclean, re

all : $(NAME)

clean :
	rm -rf $(OUTPUT)

fclean : clean
	rm $(NAME)
re : fclean all
