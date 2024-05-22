# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amylle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:58:06 by amylle            #+#    #+#              #
#    Updated: 2024/05/22 16:10:06 by amylle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= ./srcs
OBJ_DIR	= ./obj
INC_DIR	= ./includes

SRCS	=	./srcs/ft_sort.c ./srcs/operations_reverse_rotate.c \
			./srcs/calculate_moves_cost.c ./srcs/ft_checkinputerrors.c \
			./srcs/operations_rotate.c ./srcs/operations_swap.c ./srcs/operations_push.c \
			./srcs/stack_utils2.c ./srcs/ft_initstack.c ./srcs/stack_utils.c \
			./srcs/ft_error.c ./srcs/moves_a.c

MAIN		=	./srcs/main.c
BONUS_SRC	=	./bonus/checker_bonus.c

OBJS 		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wextra -Wall -Werror
INCLUDE	= -L./libft -lft -Iincludes
RM		= rm -rf
LIBFT	= libft/libft.a

NAME	= push_swap
BONUS	= checker

all:	$(NAME)
bonus:	$(NAME) $(BONUS)

$(OBJ_DIR)/%.o: %.c $(LIBFT)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):	
		@make -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
				@echo Compiling $(NAME)
				$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(INCLUDE) -o $(NAME)

$(BONUS):	$(OBJS) $(LIBFT)
				@echo Compiling $(BONUS)
				@$(CC) $(CFLAGS) $(BONUS_SRC) $(OBJS) $(INCLUDE)-o $(BONUS)
clean:	
				$(RM) $(OBJ_DIR)
				make clean -C ./libft

fclean:		clean
				$(RM) $(NAME) $(BONUS)
				make fclean -C ./libft

re:			fclean all

.PHONY: all clean fclean re bonus
