# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 20:15:58 by sabdulba          #+#    #+#              #
#    Updated: 2024/11/09 00:38:52 by sabdulba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_strings.c
MAIN_OBJ = ft_printf.o
OBJ := $(SRC:%.c=%.o)
LIBC = ar rc $(NAME)
LIBR = ranlib $(NAME)
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror
EXEC = program

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(LIBC) $(OBJ)
	$(LIBR)

all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME) $(EXEC)
		
re : fclean all

run : $(NAME) $(MAIN_OBJ)
	  $(CC)	$(FLAG) $(MAIN_OBJ) -L. -lftprintf -o $(EXEC)
	  ./$(EXEC)