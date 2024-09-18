NAME := test

COMPILER := cc

SOURCES := test.c

LIBRARY := libft.a

OUTPUT := $(SOURCES:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o : %.c $(LIBRARY)
	$(COMPILER) $(CCFLAGS) $(LIBRARY) -c $< -o $@ 

$(NAME) : $(OUTPUT)

.PHONY := all, clean, fclean, re

all : $(NAME)

clean :
	rm $(OUTPUT)

fclean : clean

re : fclean all
