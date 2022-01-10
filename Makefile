# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 01:20:15 by phnguyen          #+#    #+#              #
#    Updated: 2022/01/10 18:28:23 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

CC := gcc
LIBFT := libft.a

CFLAGS += -Wall -Werror -Wextra
#CFLAGS += -g
#CFLAGS += -fsanitize=address
CFLAGS += -O2

SRCDIR := src/
OBJDIR := obj/
LIBFTDIR := libft/
INCL := includes/

C_FILE =	main \
			parser \
			parser_utils \
			graph \
			graph_utils \
			solver \
			solver_init \
			node

SRC =	$(addprefix $(SRCDIR), $(addsuffix .c, $(C_FILE)))
OBJ = 	$(addprefix $(OBJDIR), $(addsuffix .o, $(C_FILE)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCL)/*
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCL) -I$(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

norm:
	make -C $(LIBFTDIR) norm
	norminette $(SRCDIR) $(INCL)

.PHONY = all clean fclean re norm