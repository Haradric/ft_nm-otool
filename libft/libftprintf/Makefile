#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 14:06:34 by mbraslav          #+#    #+#              #
#    Updated: 2017/02/01 14:06:36 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
override CFLAGS += -Wall -Wextra -Werror
SOURCE =	src/ft_printf.c          \
			src/read_modifiers.c     \
			src/read_modifiers2.c    \
			src/read_arguments.c     \
			src/read_arguments2.c    \
			src/clean_description.c  \
			src/useful_things.c      \
			src/processing.c         \
			src/processing_percent.c \
			src/processing_x.c       \
			src/processing_s.c       \
			src/processing_ls.c      \
			src/processing_c.c       \
			src/processing_o.c       \
			src/processing_di.c      \
			src/processing_u.c       \
			src/processing_p.c       \
			src/wchar.c

OBJECT = $(SOURCE:.c=.o)
NAME   = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECT)
	@echo "\033[34mcreating $(NAME)\033[39m"
	@ar rc $(NAME) $(OBJECT)
	@echo "\033[34mgenerating index to $(NAME)\033[39m"
	@ranlib $(NAME)

%.o: %.c
	$(CC) -Iinclude -Isrc $(CFLAGS) -o $@ -c $<

clean:
	@echo "\033[34mremoving object files of libftprintf\033[39m"
	@rm -f $(OBJECT)

fclean:
	@echo "\033[34mremoving object files of libftprintf\033[39m"
	@rm -f $(OBJECT)
	@echo "\033[34mremoving $(NAME)\033[39m"
	@rm -f $(NAME)

re: fclean all
