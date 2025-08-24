# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 12:44:04 by ivmirand          #+#    #+#              #
#    Updated: 2025/08/24 18:31:29 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:= /bin/bash

NAME		:=	philosophers

DIR_OBJS	:=	objs
DIR_SRCS	:=	src
DIR_INC		:=	inc

SRC_FILES	:=	check_args.c \
			iter_over_philosophers.c \
			main.c \
			philosophers.c \
			forks.c \
			table.c \
			timers.c

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(SRC_FILES))
OBJS		:=	$(addprefix $(DIR_OBJS)/, $(SRC_FILES:.c=.o))

CC			:=	cc
INCLUDE		:=	-I $(DIR_INC)
MKDIR		:=	mkdir -p
RM			:=	rm -rf 

all			:	$(NAME)

$(NAME)		:	$(DIR_OBJS) $(OBJS)
				$(CC) $(CCFLAGS) $(DBFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS)	:	
				$(MKDIR) $(DIR_OBJS)
			
$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c
				$(CC) $(CCFLAGS) $(DBFLAGS) $(FLAGS) $(INCLUDE) -c $< -o $@

clean		:
				$(RM) $(DIR_OBJS)
	
fclean		:	clean valclean
				$(RM) $(NAME)

re			:	fclean all

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
	CCFLAGS := -Wall -Wextra -Werror
endif

##################################################

# --- Valgrind rules --- #

# valgrind_report salida del resultado de valgrind
# valgrind.supp fichero de supresion para ignorar fugas externas

# por ahora con --trace-children=no ignoraremos los procesos hijos
# cuando querramos seguir a los hijos cambiar a yes, 
# añadir la regla --gen-suppressions=all y por ultimo copiar el resultado en 
# el .supp para ignorarlos.
VALGRIND_LOG	:=	valgrind_report.txt
SUPPRESSIONS	:=	valgrind.supp
TEMP			:=	.$(SUPPRESSIONS).temp
KEEP			:=	.$(SUPPRESSIONS).keep

valgrind	:	all
		valgrind -s \
			--tool=memcheck \
			--track-fds=yes \
			--leak-check=full \
			--track-origins=yes \
			--show-leak-kinds=all \
			--trace-children=no \
			--log-file=$(VALGRIND_LOG) \
			--gen-suppressions=all \
			./$(NAME)
			(cat $(VALGRIND_LOG) | grep -v "==" | tr -d "\n" | \
				sed 's/}/}\n/g' | sort -u > $(SUPPRESSIONS)); touch $(KEEP); \
			while [ "$$(head -n1 $(SUPPRESSIONS))" != "" ] ; do \
				head -n1 $(SUPPRESSIONS) | sed 's/  /   \n/g' | sed 's/}/\n}/g' > $(TEMP); cat $(TEMP); \
				read -n1 -p "Would you like to save this suppression? <y/n>: " ans; echo; \
				if [[ "$$ans" == "y" ]]; then \
					read -p "What would you like to name this suppression?: " supp_name; \
					safe_name=$$(printf '%s' "$$supp_name" | sed 's/[&/@]/\\&/g'); \
					head -n1 $(SUPPRESSIONS) | sed "s@<insert_a_suppression_name_here>@$$safe_name@" > $(TEMP); \
					head -n1 $(TEMP) | sed 's/  /   \n/g' | sed 's/}/\n}/g' >> $(KEEP); \
				fi; \
				tail -n+2 $(SUPPRESSIONS) > $(TEMP) && mv $(TEMP) $(SUPPRESSIONS) ; \
			done; echo "Finished."; \
			mv $(KEEP) $(SUPPRESSIONS)

valclean	:	
			rm -f $(VALGRIND_LOG)
			rm -f $(SUPPRESSIONS)
			@rm -f $(TEMP)
			@rm -f $(KEEP)

.PHONY	: all clean fclean re valgrind
