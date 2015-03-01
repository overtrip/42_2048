# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/28 10:58:38 by jealonso          #+#    #+#              #
#    Updated: 2015/03/01 22:32:10 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTPATH = libft

LIBFT = $(LFTPATH)/libft.a

INCLPATH = includes

OBJSPATH = objs

SRCSPATH = srcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
		 -I $(INCLPATH) -I $(LFTPATH)/$(INCLPATH)

LDFLAGS	= -L $(LFTPATH) -lft -lncurses

NAME = game_2048

SRCS = \
		main.c \
		aff_win.c \
		create_tab.c \
		ft_count_z.c \
		ft_win.c \
		ft_fail.c \
		update_up.c \
		update_down.c \
		update_right.c \
		update_left.c \
		addrandom.c \
		free_tab.c \
		ft_fuse.c \

OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HFILES = ft_2048.h

HEAD = $(patsubst %.h, includes/%.h, $(HFLIES))

all: $(OBJSPATH) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJSPATH)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	rm -f $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	mkdir $@

$(LIBFT):
	$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
