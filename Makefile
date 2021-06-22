# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/06/22 20:52:22 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = checker
NAME = push_swap

PUSH_SWAP_SRC	= push_swap.c clear_stack.c stack_new.c stack_sort.c stack_add_back.c create_stack.c stack_size.c\
		operator.c swap.c push.c rotate.c rrotate.c sort_three.c sort_five.c put_index.c sort.c print_stack.c operator_mix.c find_index.c\
		init_var.c
CHECKER_SRC	= checker.c clear_stack.c stack_new.c stack_sort.c stack_add_back.c create_stack.c stack_size.c\
		operator.c swap.c push.c rotate.c rrotate.c sort_three.c sort_five.c put_index.c sort.c print_stack.c operator_mix.c find_index.c\
		init_var.c check_issort.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(PUSH_SWAP_SRC))
BONUS_SRCS 	= $(addprefix $(SRCDIR), $(CHECKER_SRC))
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra
RM 		= rm -f

./srcs/%.o:		./srcs/%.c
		$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

all:	$(LIBNAME) $(NAME)

bonus: $(LIBNAME) $(BONUS)

$(NAME): $(OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -lft -L. -o $(NAME) $(OBJS)

$(LIBNAME):
		@$(MAKE) -C $(LIBDIR) bonus
		@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)



$(BONUS): $(BONUS_OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -lft -L. -o $(BONUS) $(BONUS_OBJS) 

clean:
		$(RM) $(OBJS)
		$(RM) $(BONUS_OBJS)

fclean:		clean
		$(RM) $(NAME) $(LIBNAME)
		$(RM) $(BONUS)
		@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
