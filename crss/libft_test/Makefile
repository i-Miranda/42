NAME := libfttest

COMPILER := cc

SOURCES := test.c

LIBRARY := libft.h

OUTPUT := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o : %.c $(LIBRARY)
	$(COMPILER) $(CCFLAGS) -c $< -o $@ 

$(NAME) : $(OUTPUT)

.PHONY := all, clean, fclean, re

all : $(NAME)

clean :
	rm -rf $(OUTPUT)

fclean : clean
	rm $(NAME)
re : fclean all
