# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 22:10:05 by ivmirand          #+#    #+#              #
#    Updated: 2026/02/26 16:51:59 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ex00

DIR_OBJS	:=	objs

SOURCES		:=	main.cpp \
				Bureaucrat.cpp

OBJS		:=	$(addprefix $(DIR_OBJS)/, $(SOURCES:.cpp=.o))

CXX			:=	c++
INC			:=	-I$(DIR_INC)


all	:	$(NAME)

$(NAME)			:	$(DIR_OBJS)	$(OBJS)
	$(CXX) $(CXXFLAGS) $(DBFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS)		:
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o	: %.cpp
	$(CXX) $(CXXFLAGS) $(DBFLAGS) -c $< -o $@

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
			rm -f $(SUPPRESSIONS)
			@rm -f $(TEMP)
			@rm -f $(KEEP)

.PHONY : all \
	clean \
	fclean \
	re \
	valgrind \
	valclean 
