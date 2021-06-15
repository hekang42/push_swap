# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/06/15 14:06:11 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= push_swap.c ft_list.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a

NAME	= push_swap

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra
RM 		= rm -f

%.o:		%.c
		$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME) $(OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -o $(NAME) $(OBJS) $(LIBNAME)

$(LIBNAME):
		@$(MAKE) -C $(LIBDIR) bonus
		@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) $(LIBNAME)
		@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
