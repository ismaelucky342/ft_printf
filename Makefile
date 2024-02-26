# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 12:32:36 by ismherna          #+#    #+#              #
#    Updated: 2024/02/26 12:37:11 by ismherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= ./libft/libft.a
LIBFT_DIR	= ./libft

SRC			= ./srcs

PRINTF_SRCS	= ft_printf.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_digit.c \
				ft_print_digitX.c \
				ft_hexformat.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
CP			= cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJS)

$(LIBFT):	$(LIBFT_DIR)
				@$(MAKE) -C $(LIBFT_DIR)


%.o: 		$(SRC)/%.c 
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(MAKE) clean -C $(LIBFT_DIR)
				@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
