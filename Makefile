# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 12:04:55 by kbaridon          #+#    #+#              #
#    Updated: 2025/05/14 01:11:20 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[0;32m
ORANGE=\033[38;5;214m

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -L $(MLIBX) -lmlx -lXext -lX11 -lm -lz -lXfixes

SRCDIR = src
INCDIR = includes
LIBFT = lib/libft
MLIBX = lib/minilibx-linux

INCLUDES = -I $(MLIBX)

HEADERS =	$(INCDIR)/engine/image.h \
			$(INCDIR)/engine/input.h \
			$(INCDIR)/engine/render.h \
			$(INCDIR)/engine/raycast.h \
			$(INCDIR)/engine/vector.h \
			$(INCDIR)/engine/window.h \
			$(INCDIR)/engine/wall.h \
			$(INCDIR)/player.h \
			$(INCDIR)/common.h \
			$(INCDIR)/system.h \
			$(INCDIR)/game.h \
			$(INCDIR)/map.h \
			$(LIBFT)/libft.h

SRC =	main.c \
		parsing/parsing.c parsing/map.c parsing/parse_utils.c parsing/errors.c \
		parsing/check.c \
		engine/input.c \
		engine/game.c \
		engine/system.c \
		engine/raycast.c \
		engine/draw_wall.c \
		engine/draw_floor_ceiling.c \
		graphic/image.c \
		graphic/render.c \
		graphic/debug.c \
		graphic/pixel.c \
		graphic/window.c \
		player/player_controller.c \
		player/player_movement.c \
		player/hide_mouse.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all:	$(NAME)

bonus:	$(NAME)

$(NAME):	$(OBJS)
	@if [ ! -f $(LIBFT)/libft.a ]; then \
	echo "$(ORANGE)Compiling libft..."; \
	$(MAKE) --no-print-directory -C $(LIBFT); \
	fi
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LFLAGS) $(INCLUDES) -o $(NAME)
	@echo "$(ORANGE)Compiling cub3d..."
	@echo "$(GREEN)Compilation completed !"

$(SRCDIR)/%.o:	$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -I $(LIBFT) -I $(INCDIR) -I $(MLIBX) -c $< -o $@

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