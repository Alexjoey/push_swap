# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amylle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:58:06 by amylle            #+#    #+#              #
#    Updated: 2024/05/10 14:47:16 by amylle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= ./srcs
OBJ_DIR	= ./obj
INC_DIR	= ./includes

SRCS	=	./srcs/ft_sort.c ./srcs/operations_reverse_rotate.c ./srcs/main.c \
			./srcs/calculate_moves_cost.c ./srcs/ft_checkinputerrors.c \
			./srcs/operations_rotate.c ./srcs/operations_swap.c ./srcs/operations_push.c \
			./srcs/stack_utils2.c ./srcs/ft_initstack.c ./srcs/stack_utils.c \
			./srcs/ft_error.c ./srcs/moves_a.c 

MAIN		=	./srcs/main.c
BONUS_SRC	=	./bonus/checker_bonus.c

CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g
INCLUDE	= -Llibft -lft -I$(INC_DIR)
RM		= rm -rf

NAME	= push_swap
BONUS	= checker

all:	$(NAME)
bonus:	$(NAME) $(BONUS)
$(NAME):	$(SRCS)
				make -C ./libft
				@echo Compiling $(NAME)
				@$(CC) $(CFLAGS) $(MAIN) $(SRCS) $(INCLUDE) -o $(NAME)

$(BONUS):	$(SRCS)
				@echo Compiling $(BONUS)
				@$(CC) $(CFLAGS) $(BONUS_SRC) $(SRCS) $(INCLUDE) -o $(BONUS)
clean:	
				$(RM) $(OBJS)
				make clean -C ./libft

fclean:		clean
				$(RM) $(NAME) $(BONUS)
				make fclean -C ./libft

re:			fclean all
