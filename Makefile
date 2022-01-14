# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 14:05:24 by ldamiens          #+#    #+#              #
#    Updated: 2022/01/14 15:25:28 by ldamiens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=======================#
#		Variables       #
#=======================#

#-------- Output --------#

NAME = libftprintf.a

#-------- Paths --------#

PATH_INCLUDE 	= includes
PATH_SOURCE 	= srcs
PATH_OBJECT 	= objs

SRC				= 	utils/ft_putchar.c \
					utils/ft_putnbr_base.c \
					utils/ft_putnbr.c \
					utils/ft_putstr.c  \
					utils/ft_strlen.c \
					ft_printf.c

#-------- Objects --------#

OBJECT 			= $(addprefix $(PATH_OBJECT)/, $(SRC:.c=.o))

#-------- Includes --------#

INCLUDE			= $(addprefix $(PATH_INCLUDE)/, ft_printf.h)

#-------- Macro --------#

CC 				= gcc
FLAGS 			= -Wall -Wextra -Werror
RM 				= rm -rf
LIBC 			= ar rc
MAKEFILE		= Makefile

#-------- Rules --------#

all 	:	$(NAME)

$(NAME) :		$(OBJECT)
					$(LIBC) $(NAME) $(OBJECT)

bonus 	:			$(OBJECT) $(OBJECT_BONUS)
						$(LIBC) $(NAME) $(OBJECT) $(OBJECT_BONUS)

$(PATH_OBJECT)/%.o 	:	$(PATH_SOURCE)/%.c $(INCLUDE) $(MAKEFILE)
							@mkdir -p $(@D)
							$(CC) $(FLAGS) -I $(PATH_INCLUDE) -c $< -o $@

#-------- Clean --------#

clean	:
	$(RM) $(OBJECT) $(OBJECT_BONUS)

fclean	: clean
	$(RM) $(NAME)

re 		: fclean all

.PHONY	:		all bonus clean fclean re