# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 01:20:15 by phnguyen          #+#    #+#              #
#    Updated: 2021/12/14 05:26:34 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

CC := gcc

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -g2 -fsanitize=address

SRCDIR = src/
OBJDIR = obj/
INCL = includes/

C_FILE =	main get_next_line split_charset utils utils_list \
			parser

SRC =	$(addprefix $(SRCDIR), $(addsuffix .c, $(C_FILE)))
OBJ = 	$(addprefix $(OBJDIR), $(addsuffix .o, $(C_FILE)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCL)/*
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCL)

clean:
	rm -r $(OBJDIR)

fclean: clean
	rm $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR) $(INCL)

.PHONY = all clean fclean re