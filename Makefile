# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 12:04:55 by kbaridon          #+#    #+#              #
#    Updated: 2025/05/13 15:10:22 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
ORANGE=\033[38;5;214m

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OTHERFLAGS = -L $(LIBDIR) -lmlx -lXext -lX11 -lm -lz

SRCDIR = src
LIBFT = lib/libft
LIBDIR = lib/minilibx-linux
INCLUDES = -I $(LIBDIR)
INCDIR = includes

HEADERS = $(INCDIR)/cub3d.h $(LIBFT)/libft.h
SRC =	cub3d.c \
		parsing/parsing.c parsing/map.c parsing/parse_utils.c parsing/errors.c \
		init/init.c init/init_utils.c init/end.c  \
		game/event_listener.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	@if [ ! -f $(LIBFT)/libft.a ]; then \
	echo "$(ORANGE)Compiling libft..."; \
	$(MAKE) --no-print-directory -C $(LIBFT); \
	fi
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(OTHERFLAGS) $(INCLUDES) -o $(NAME)
	@echo "$(ORANGE)Compiling cub3d..."
	@echo "$(GREEN)Compilation completed !"

$(SRCDIR)/%.o:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -I $(LIBFT) -I $(INCDIR) -I $(LIBDIR) -c $< -o $@

$(OBJS):	$(HEADERS)

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFT)
	@echo "$(ORANGE)Cleaning libft..."
	@rm -rf $(OBJS)
	@echo "$(ORANGE)Cleaning cub3d..."
	@echo "$(GREEN)Cleaning of objects completed !"

fclean:	clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@rm -rf $(NAME)
	@echo "$(ORANGE)Cleaning executables..."
	@echo "$(GREEN)Cleaning of executables completed !"

re: fclean all

.PHONY: all clean fclean re