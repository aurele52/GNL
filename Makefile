# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <audreyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 01:52:00 by audreyer          #+#    #+#              #
#    Updated: 2022/08/08 15:54:43 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#

NAME = gnl.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

INC = ./include/get_next_line.h
INCB = ./include/get_next_line_bonus.h

AR = ar rcs

SRC = $(addprefix $(SRC_DIR),$(FILE))
SRCB = $(addprefix $(SRC_DIR),$(FILEB))

FILE = get_next_line.c \
	   get_next_line_utils.c \

FILEB = get_next_line_bonus.c \
	   get_next_line_utils_bonus.c\

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

SRC_DIR = src/

OBJ_DIR = src/

$(NAME):	$(OBJ) $(INC)
		$(CC) $(FLAGS) -c $(SRC)
		$(AR) $(NAME) $(OBJ)

bonus: $(OBJB) $(INCB)
		$(CC) $(FLAGS) -c $(SRCB)
		$(AR) $(NAME) $(OBJB)


all: $(NAME)

clean:
		$(RM) $(OBJ) $(OBJB)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

