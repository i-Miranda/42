# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 22:10:05 by ivmirand          #+#    #+#              #
#    Updated: 2025/10/01 22:41:27 by ivmirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	account

DIR_SRC		:=	src
DIR_INC		:=	inc
DIR_OBJS	:=	objs

SOURCES		:= Account.cpp \
				tests.cpp 

SRCS		:= 	$(addprefix $(DIR_SRC)/, $(SOURCES))
OBJS		:=	$(addprefix $(DIR_OBJS)/, $(SOURCES:.cpp=.o))

CXX			:=	c++
INC			:=	-I$(DIR_INC)


all	:	$(NAME)

$(NAME)			:	$(DIR_OBJS)	$(OBJS)
	$(CXX) $(CXXFLAGS) $(DBFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS)		:
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o	:	$(DIR_SRC)/%.cpp
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
SUPPRESSIONS	:=	valgrind.supp
TEMP			:=	.$(SUPPRESSIONS).temp
KEEP			:=	.$(SUPPRESSIONS).keep

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

valgrind_supp	:	all
		valgrind -s \
			--tool=memcheck \
			--leak-check=full \
			--track-origins=yes \
			--show-leak-kinds=all \
			--log-file=$(VALGRIND_LOG) \
			--gen-suppressions=all \
			./$(NAME) $(ARGS)
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

.PHONY : all \
	clean \
	fclean \
	re \
	valgrind \
	valgrind_supp \
	valclean 
