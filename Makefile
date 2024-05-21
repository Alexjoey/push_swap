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

SRCS	= ./srcs/*
MAIN	= ./main.c
BONUS_SRC	= ./bonus/checker_bonus.c
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g
INCLUDE	= -Llibft -lft -Iincludes
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
