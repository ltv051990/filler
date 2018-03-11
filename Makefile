#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 15:26:02 by tlutsyk           #+#    #+#              #
#    Updated: 2018/01/12 15:26:02 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = players/tlutsyk.filler
CFILES = main.c ft_start_read.c get_next_line.c ft_fill_struct.c ft_audit.c \
		move_figure.c

OFILES = $(CFILES:.c=.o)
FOLDER = libft

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES)

$(NAME): $(OFILES)
		make -C $(FOLDER)
		@gcc $(OFILES) -L $(FOLDER) -lft -o $(NAME)

clean:
	@/bin/rm -f $(OFILES)
	make clean -C $(FOLDER)

fclean: clean
	@/bin/rm -f $(NAME)
	make fclean -C $(FOLDER)

re: fclean all

.PHONY: all clean fclean