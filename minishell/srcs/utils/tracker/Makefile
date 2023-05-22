# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Romain <Romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 22:16:56 by rcuminal          #+#    #+#              #
#    Updated: 2023/05/16 21:23:37 by Romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include Config/Sources.mk
-include Config/Header.mk

#################################################################################
#									Colors										#
#################################################################################

CCEND		=  \033[0m
CCYAN		=  \033[34m
CGREEN		=  \033[33m
CCRED		=  \033[31m
CCPURPLE	=  \033[35m
GREY		= \033[4;34m
RED			= \033[1;31m
GREEN		= \033[3;32m
YELLOW		= \033[2;49;33m
BLUE		= \033[4;34m
BLUEE		= \033[3;34m
PURPLE		= \033[3;35m
CYAN		= \033[3;36m
RESET		= \033[0m
ICONOK		= \033[1;32m
ICONKO		= \033[1;31m
CO_DELET	= \033[4;31m
CO_A_OUT	= \033[96m
WHITE		= \033[1;49;97m

#################################################################################
#									Variables									#
#################################################################################

NAME 		= libtracker.a
OBJ_DIR		= objs
OBJS		= $(SRCS:%.c=%.o)
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))
CFLAGS		= -Wall -Werror -Wextra -I ./include
CONFIG		= $(shell find [0-9a-zA-Z]* -type d -name "Config")
MK_DIR		= Config 

#################################################################################
#									Compilation C								#
#################################################################################

all: gmk $(NAME)

$(NAME): $(OBJ_PATH)
	@ar rcs $(NAME) $(OBJ_PATH) $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Clean										#
#################################################################################

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f $(NAME)

#################################################################################
#									Gen MK										#
#################################################################################

$(MK_DIR):
ifneq ($(CONFIG), Config)
	@mkdir Config
endif

gmk: $(MK_DIR)
	@echo "SRCS += " > ./Config/Sources.mk
	@find srcs -name '*.c' | sed 's/^/SRCS += /' >> ./Config/Sources.mk
	@echo "HEADER += " > ./Config/Header.mk
	@find Include -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: clean fclean all

.PHONY: all clean fclean re