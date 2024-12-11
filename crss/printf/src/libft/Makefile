NAME := libft.a

HEADER := ../../includes/libft.h

COMPILER := cc

SOURCES := ft_isdigit.c \
	ft_isalnum.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c 

OBJ_O := $(SOURCES:.c=.o)

OUTPUT := ../../output/libft/

CCFLAGS := -Wall -Wextra -Werror

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
	CCFLAGS := -Wall -Wextra -Werror
endif

%.o: %.c $(HEADER)
		$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $(OUTPUT)$@

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently
# -s writes object-files
ARFLAGS := -rcs

$(NAME): $(OBJ_O) $(HEADER) 
	ar $(ARFLAGS) $(NAME) ../../output/libft/*.o 

clean:
	rm -rf $(OBJ_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)

re: fclean

.PHONY: clean fclean re
