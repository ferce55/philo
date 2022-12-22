# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:23:02 by rsarri-c          #+#    #+#              #
#    Updated: 2022/12/22 23:01:17 by rsarri-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRCS		=	./srcs/main.c ./srcs/init.c ./srcs/utils.c ./srcs/philo_utils.c ./srcs/philo.c

CC			=	@gcc
CFLAGS		=	-Wall -Werror -Wextra
SANITIZE	=	-fsanitize=thread
RM			=	rm -rf

OBJS		=	$(SRCS:.c=.o)

COMP		=	$(CC) $(CFLAGS) $(SANITIZE) $(SRCS) $(LIBFT) -o $(NAME)

$(NAME):	$(OBJS)
		@echo "---------   Compiling   -----------"
		$(COMP)
		@echo "--------------DONE!!---------------"

all:		${NAME}

clean:
		@echo "-------      Cleaning       -------"
		@$(RM) $(OBJS)
		@echo "--------------DONE!!---------------"

fclean:	clean
		@echo "-------      Cleaning       -------"
		@$(RM) $(NAME)
		@echo "--------------DONE!!---------------"

re:		fclean all

.PHONY:	all fclean clean re