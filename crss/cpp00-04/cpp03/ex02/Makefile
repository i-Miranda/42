# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 22:10:05 by ivmirand          #+#    #+#              #
#    Updated: 2026/03/29 15:36:21 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ex02

DIR_OBJS	:=	objs

SOURCES		:=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp 

OBJS		:=	$(addprefix $(DIR_OBJS)/, $(SOURCES:.cpp=.o))

CXX			:=	c++

all	:	$(NAME)

$(NAME)			:	$(DIR_OBJS)	$(OBJS)
	$(CXX) $(CXXFLAGS) $(DBFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS)		:
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o	:	%.cpp
	$(CXX) $(CXXFLAGS) $(DBFLAGS) $(INC) -c $< -o $@

clean			:
	rm -rf	$(DIR_OBJS)

fclean			:	clean valclean
	rm -rf	$(NAME)

re				:	fclean all

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
	CXXFLAGS :=
	DBFLAGS :=
else 
	CXXFLAGS := -Wall -Werror -Wextra -std=c++98
endif

##################################################

# --- Valgrind rules --- #

VALGRIND_LOG	:=	valgrind_report.txt

valgrind	:	all 
		valgrind -s \
			--tool=memcheck \
			--leak-check=full \
			--track-origins=yes \
			--show-leak-kinds=all \
			./$(NAME) $(ARGS)

valgrind_log	:	all 
		valgrind -s \
			--tool=memcheck \
			--leak-check=full \
			--track-origins=yes \
			--show-leak-kinds=all \
			--log-file=$(VALGRIND_LOG) \
			./$(NAME) $(ARGS)

valclean	:	
			rm -f $(VALGRIND_LOG)

.PHONY : all \
	clean \
	fclean \
	re \
	valgrind \
	valgrind_log \
	valclean 
