# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/06/21 18:17:32 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= push_swap.c ft_list.c clear_stack.c stack_new.c stack_sort.c stack_add_back.c create_stack.c stack_size.c\
		operator.c swap.c push.c rotate.c rrotate.c sort_three.c sort_five.c put_index.c sort.c print_stack.c

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
		$(GCC) $(GCCFLAG) -I$(INCDIR) -fsanitize=address -o $(NAME) $(OBJS) $(LIBNAME)

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
