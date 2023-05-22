# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Romain <Romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 19:25:44 by rcuminal          #+#    #+#              #
#    Updated: 2023/05/16 23:14:58 by Romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Setting Color
CCEND 		=   	\033[0m
CCYAN 		=   	\033[34m
CGREEN		=   	\033[33m
CCRED 		=   	\033[31m
CCPURPLE 	=   	\033[35m

EXEC 		= 	 push_swap
NAME 		= 	 $(EXEC).a
CC 			= 	 gcc

PATH_SRC	=	./srcs/
PATH_OBJ	=	./objs/

SRC 		=	push_swap.c       \
				utils.c \
				operations.c \
				check.c \
				castrois.c \
				index.c \
				utilsindex.c \
				tab.c \
				opeswap.c

OBJ_SRC		=	$(SRC:.c=.o)

SRC_O		=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S		=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))

HEADER 		= 	includes/$(EXEC).h
MK			= 	Makefile
SAN 		= 	-g3 -fsanitize=address
FLAGS 		= 	-Wall -Werror -Wextra -ggdb
LIB			= 	-llibft
DEPEND		= 	libft/objs/libft.a

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER) $(MK)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) $(FLAGS) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@make -C libft
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) $(PATH_OBJ)$(NAME) $(DEPEND) -o $(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

san: $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN)Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@make -C libft
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) $(FLAGS) $(SAN) $(PATH_OBJ)$(NAME) $(DEPEND) -o $(PATH_OBJ)$(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation with sanitize $(EXEC)...$(CCEND)\n"

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

fclean: clean
	@make fclean -C libft
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(PATH_OBJ)*.a
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f Tags
	@-/bin/rm -f $(EXEC)
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

git:	fclean
	@git add .
	@git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	@git push



.PHONY: all clean fclean re san
.SILENT :
re: fclean all
