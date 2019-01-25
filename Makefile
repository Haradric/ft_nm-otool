#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <mbraslav@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 19:20:34 by mbraslav          #+#    #+#              #
#    Updated: 2019/01/23 19:20:42 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
override CFLAGS  += -Wall -Wextra -Werror
override LDFLAGS +=

FT_NM_SOURCES    =  ft_nm/src/main.c                   \
                    ft_nm/src/ft_nm.c                  \
                    ft_nm/src/file_types_handlers.c    \
                    ft_nm/src/sections_index.c         \
                    ft_nm/src/macho32.c                \
                    ft_nm/src/macho64.c                \
                    ft_nm/src/fat.c                    \
                    ft_nm/src/sort.c                   \
                    ft_nm/src/print.c                  \
                    ft_nm/src/error.c                  \
                    ft_nm/src/utils.c                  \
                    ft_nm/src/mode.c

FT_OTOOL_SOURCES =  ft_otool/src/main.c                \
                    ft_otool/src/ft_otool.c            \
                    ft_otool/src/file_types_handlers.c \
                    ft_otool/src/macho32.c             \
                    ft_otool/src/macho64.c             \
                    ft_otool/src/fat.c                 \
                    ft_otool/src/print.c               \
                    ft_otool/src/error.c               \
                    ft_otool/src/utils.c               \
                    ft_otool/src/mode.c

FT_NM_OBJECTS    = $(FT_NM_SOURCES:.c=.o)
FT_OTOOL_OBJECTS = $(FT_OTOOL_SOURCES:.c=.o)

FT_NM    = bin/ft_nm
FT_OTOOL = bin/ft_otool
LIBFT    = libft/libft.a

all: $(FT_NM) $(FT_OTOOL)

$(FT_NM): $(LIBFT) $(FT_NM_OBJECTS)
	@if [ ! -d "bin" ]; then mkdir bin; fi
	@echo "\033[34mcreating $@\033[39m"
	@$(CC) $(LDFLAGS) $(LIBFT) $(FT_NM_OBJECTS) -o $@

$(FT_OTOOL): $(LIBFT) $(FT_OTOOL_OBJECTS)
	@if [ ! -d "bin" ]; then mkdir bin; fi
	@echo "\033[34mcreating $@\033[39m"
	@$(CC) $(LDFLAGS) $(LIBFT) $(FT_OTOOL_OBJECTS) -o $@

$(LIBFT):
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -Ift_nm/include -Ift_otool/include -Ilibft/include -c $< -o $@

clean:
	@make -C libft clean
	@echo "\033[34mremoving object files\033[39m"
	@rm -f $(FT_NM_OBJECTS) $(FT_OTOOL_OBJECTS)

fclean:
	@make -C libft fclean
	@echo "\033[34mremoving object files of ft_nm and ft_otool\033[39m"
	@rm -f $(FT_NM_OBJECTS) $(FT_OTOOL_OBJECTS)
	@echo "\033[34mremoving ft_nm and ft_otool\033[39m"
	@rm -rf bin

re: fclean all
