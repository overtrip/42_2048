# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:51:42 by jealonso          #+#    #+#              #
#    Updated: 2015/02/24 18:55:11 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSPATH	=	srcs
INCLPATH	=	includes
OBJSPATH	=	objs

NAME = libft.a

SRCS = \
		ft_atoi.c\
		ft_itoa.c\
		ft_memcmp.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c

ASM = ~/.brew/bin/nasm

AR = ar

AFLAGS = -f macho64

SRCSS = \
		ft_bzero.s\
		ft_cat.s\
		ft_isalnum.s\
		ft_isalpha.s\
		ft_isascii.s\
		ft_isdigit.s\
		ft_islower.s\
		ft_isprint.s\
		ft_isupper.s\
		ft_memalloc.s\
		ft_memchr.s\
		ft_memcpy.s\
		ft_memset.s\
		ft_puts.s\
		ft_strcat.s\
		ft_strcmp.s\
		ft_strdup.s\
		ft_strequ.s\
		ft_strlen.s\
		ft_tolower.s\
		ft_toupper.s

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCLPATH)

OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS)) \
	   $(patsubst %.s, $(OBJSPATH)/%.o, $(SRCSS))

HFILES = libft.h

HEAD = $(patsubst %.h, includes/%.h, $(HFILES))

all: $(OBJSPATH) $(NAME)

$(NAME): $(OBJS)
	$(AR) -rc $@ $^
	ranlib $@

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJSPATH)/%.o: $(SRCSPATH)/%.s
	$(ASM) $(AFLAGS) $< -o $@

clean:
	rm -rf $(OBJSPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJSPATH):
	mkdir $@

test:
	@echo $(OBJS)
