# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:48:04 by ismherna          #+#    #+#              #
#    Updated: 2025/03/03 01:08:42 by ismherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	= 	includes/ft_printf.h
INCLUDE_BONUS = includes/ft_printf_bonus.h

SRC		=	src/ft_printf.c			\
			src/ft_string.c			\
			src/ft_unsigned.c		\
			src/ft_number.c			\
			src/ft_hexadecimals.c	\
			src/ft_char.c			\
			src/ft_pointers.c		\

SRC_BONUS =	src_bonus/ft_parse_bonus.c		\
			src_bonus/ft_print_sc_bonus.c	\
			src_bonus/ft_printf_bonus.c		\
			src_bonus/ft_putnbr_base_bonus.c	\

OBJ		=	${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

DEF_COLOR   =   \033[0;39m
GRAY        =   \033[0;90m
RED         =   \033[0;91m
GREEN       =   \033[0;92m
YELLOW      =   \033[0;93m
BLUE        =   \033[0;94m
MAGENTA     =   \033[0;95m
CYAN        =   \033[0;96m
WHITE       =   \033[0;97m

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo "Compiling .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}

	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
	@echo "$(BLUE)Compiled Objects:  $(words $(NAME)  ${OBJ})$(DEF_COLOR)"
	@echo "$(GREEN) Done ! $(DEF_COLOR)"
	@echo "								"
	@echo "$(GREEN)███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗$(DEF_COLOR)"
	@echo "$(GREEN)██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝$(DEF_COLOR)"
	@echo "$(GREEN)█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  $(DEF_COLOR)"
	@echo "$(GREEN)██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  $(DEF_COLOR)"
	@echo "$(GREEN)██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     $(DEF_COLOR)"
	@echo "$(GREEN)╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     $(DEF_COLOR)"
	@echo "$(GREEN)Created by Ismael Hernandez Clemente - ismherna@student.42madrid.com             $(DEF_COLOR)"                                                   

bonus: ${OBJ_BONUS}
	@echo "Compiling bonus .."
	${AR} ${NAME} ${OBJ_BONUS}
	${RN} ${NAME}

	@echo "$(GREEN)ft_printf bonus compiled!$(DEF_COLOR)"
	@echo "$(BLUE)Compiled Bonus Objects:  $(words $(NAME)  ${OBJ_BONUS})$(DEF_COLOR)"
	@echo "$(GREEN) Done ! $(DEF_COLOR)"
	@echo "								"
	@echo "$(GREEN)███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗   ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗$(DEF_COLOR)"
	@echo "$(GREEN)██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝   ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝$(DEF_COLOR)"
	@echo "$(GREEN)█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗     ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗$(DEF_COLOR)"
	@echo "$(GREEN)██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝     ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║$(DEF_COLOR)"
	@echo "$(GREEN)██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║        ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║$(DEF_COLOR)"
	@echo "$(GREEN)╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝        ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝$(DEF_COLOR)"
	@echo "$(GREEN)Created by Ismael Hernandez Clemente - ismherna@student.42madrid.com                                                            $(DEF_COLOR)"                                                                                                                       

clean:
	@echo "$(RED)Removing .o  ...$(DEF_COLOR)"
	${RM} ${OBJ} ${OBJ_BONUS}
	@echo "$(BLUE)Deleted Objects: $(words ${OBJ} ${OBJ_BONUS})  ${OBJ} ${OBJ_BONUS}$(DEF_COLOR)"
	@echo "$(GREEN)Done !"

fclean: clean
	@echo "$(RED)Removing libftprintf.a ...$(DEF_COLOR)"	
	${RM} $(NAME)
	@echo "$(BLUE)Deleted Objects:  $(words $(NAME))  $(NAME)$(DEF_COLOR)"
	@echo "$(GREEN)Done !$(DEF_COLOR)"

re: fclean all  
