NAME := libft.a

HEADER := libft.h

COMPILER := cc

SOURCES := ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c 

BONUS := ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c 

OBJ_O := $(SOURCES:.c=.o)

BONUS_O := $(BONUS:.c=.o)

CCFLAGS := -Wall -Wextra -Werror

%.o: %.c libft.h
	$(COMPILER) $(CCFLAGS) $(DBFLAGS) -c $< -o $@ -l$(LIBFT) -I include/

# -r replaces or adds a file if doesn't already exist in archive
# -c creates the archive silently 
# -s writes object-files 
ARFLAGS := -r -c -s

$(NAME): $(OBJ_O) $(HEADER) 
	ar $(ARFLAGS) $(NAME) $(OBJ_O)

all: $(NAME)

clean:
	rm -rf $(OBJ_O)
	rm -rf $(BONUS_O)

# -f ignores if file does not exist
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(BONUS_O)
	ar $(ARFLAGS) $(NAME) $(BONUS_O)

.PHONY: all clean fclean re bonus
