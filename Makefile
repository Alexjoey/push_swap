# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amylle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:58:06 by amylle            #+#    #+#              #
#    Updated: 2024/02/21 22:11:14 by amylle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/*
CC		= cc
CFLAGS	= -Wextra -Wall -Werror
INCLUDE	= -Llibft -lft -Iincludes
RM		= rm -rf

NAME	= push_swap

all:	$(NAME)

$(NAME):	$(SRCS)
				make bonus -C ./libft
				$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME)

clean:	
				$(RM) $(OBJS)
				make clean -C ./libft

fclean:		clean
				$(RM) $(NAME)
				make fclean -C ./libft

re:			fclean all
