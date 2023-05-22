#Setting Color
CCEND 			=   	\033[0m
CCYAN 			=   	\033[34m
CGREEN			=   	\033[33m
CCRED 			=   	\033[31m
CCPURPLE 		=   	\033[35m
                	
EXEC 			= 	 philo
NAME 			= 	 $(EXEC).a
NAMEBONUS 		= 	 $(EXEC)_bonus.a
CC 			= 	 gcc
                	
PATH_SRC		=	./srcs/
PATH_OBJ		=	./objs/
                	
PATH_SRC_BONUS	=	./srcs_bonus/
PATH_OBJ_BONUS	=	./objs_bonus/
                	
SRC 			=   	philo.c \
						thread.c \
						utils.c \
						utilss.c \
						operations.c \
			
                	
OBJ_SRC			=	$(SRC:.c=.o)
                	
SRC_O			=	$(addprefix $(PATH_SRC), $(SRC))
OBJ_S			=	$(addprefix $(PATH_OBJ), $(OBJ_SRC))
                	
SRC_BONUS 		=
						
                	
OBJ_SRC_BONUS	=	$(SRC_BONUS:.c=.o)
                	
SRCBONUS		=	$(addprefix $(PATH_SRC_BONUS), $(SRC_BONUS))
OBJ_BONUS		=	$(addprefix $(PATH_OBJ_BONUS), $(OBJ_SRC_BONUS))
                	
HEADER 			= 	includes/$(EXEC).h
HEADERBONUS 	= 	includes_bonus/$(EXEC)_bonus.h
MK				= 	Makefile
SAN 			= 	
FLAGS 			= 	-Wall -Werror -Wextra
#-ggdb 
LIB				= 	-llibft
DEPEND			= 

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(HEADER)
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@-$(CC) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

$(PATH_OBJ_BONUS)%.o : $(PATH_SRC_BONUS)%.c $(HEADERBONUS)
	@mkdir $(PATH_OBJ_BONUS) 2> /dev/null || true
	@-$(CC) -I ./includes -o $@ -c $<
	@printf "\r\t\033[K$(CCYAN)\t$< $(CCPURPLE)--> $(CCYAN)$@ $(CCEND)"
	@sleep 0.1

all: $(NAME)

$(NAME): $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) $(SAN) $(FLAGS) $(FLAGS) $(PATH_OBJ)$(NAME) $(DEPEND) -o $(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)...$(CCEND)\n"

bonus: $(OBJ_BONUS)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN) Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ_BONUS)$(NAMEBONUS) $(OBJ_BONUS)
	@$(CC) $(FLAGS) $(PATH_OBJ_BONUS)$(NAMEBONUS) $(DEPEND) -o $(EXEC)_bonus
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation ./$(EXEC)_bonus...$(CCEND)\n"

san: $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN)Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC)  $(SAN) $(PATH_OBJ)$(NAME) $(DEPEND) -o $(PATH_OBJ)$(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation with sanitize $(EXEC)...$(CCEND)\n"

flag: $(OBJ_S)
	@printf "\r\t\033[K$(CCYAN)[✅]\t$(EXEC) $(CCPURPLE)--> $(CCYAN)Gen Objs$(CCEND)"
	@printf "\n$(CCYAN)[✅]\t$(CCPURPLE)Creation of Objs $(EXEC)...$(CCEND)\n"
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Creation of $(NAME)...$(CCEND)\n"
	@ar rc $(PATH_OBJ)$(NAME) $(OBJ_S)
	@$(CC) $(FLAGS) $(PATH_OBJ)$(NAME) $(DEPEND) -o $(PATH_OBJ)$(EXEC)
	@printf "$(CCYAN)[✅]\t$(CCPURPLE)Compilation with sanitize $(EXEC)...$(CCEND)\n"

clean:
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(EXEC) Object...$(CCEND)\n"
	@-/bin/rm -rf $(PATH_OBJ)*.o

fclean: clean
	@printf "$(CCYAN)[✅]\t$(CCRED)Removal of $(NAME)...$(CCEND)\n"
	@-/bin/rm -f $(PATH_OBJ)*.a
	@-/bin/rm -rf $(PATH_OBJ)
	@-/bin/rm -f $(PATH_OBJ_BONUS)*.a
	@-/bin/rm -rf $(PATH_OBJ_BONUS)
	@-/bin/rm -f Tags
	@-/bin/rm -f $(EXEC)
	@-/bin/rm -f $(EXEC)_bonus
norme:
	@echo "\033[33mNorme ..."
	@norminette $(SRC)
	@norminette $(HEADER)

start:
	@sleep 0.5
	@clear
	@printf "\n\n\n$(CCYAN)"
	@printf "\t\t$(EXEC)"
	@printf "\n\n\n"
	@printf "Execution make:\n$(CCEND)"

git:	fclean
	@git add .
	@git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	@git push

.PHONY: all clean fclean re san
.SILENT :
re: fclean all