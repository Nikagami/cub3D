# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aafounas <aafounas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 17:01:35 by aafounas          #+#    #+#              #
#    Updated: 2025/04/30 17:01:37 by aafounas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                     #
################################################################################

NAME		:= cub3d
CC		:= cc
CFLAGS		:= -Wall -Werror -Wextra -Ofast -flto -march=native
# DEBUG		:= -g3 -fsanitize=address

################################################################################
#                                 PROGRAM'S SRCS                                #
################################################################################

SRCS_PATH	:= ./src
OBJS_PATH	:= ./obj
LIBS_PATH	:= ./lib

INCLUDES	:= -I ./libft/include -I ./include -I ./MLX42/include

LIBS		:= ./libft/libft.a ./MLX42/build/libmlx42.a
LIBS_FLAGS	:= -ldl -lglfw -pthread -lm

SRCS		:= isempty \
		   access \
		   arrdup \
		   ft_free \
		   free \
		   error \
		   realloc \
		   maputils \
		   main \
		   window \
		   list \
		   wallorno \
		   keyhook \
		   utils_display \
		   display \
		   raycast \
		   init \
		   utils \
		   arrlen \
		   parser \
		   reader \
		   flag \
		   arrefree \
		   isspace \
		   validation \
		   isnumber \
		   get_rgba \
		   strcmp \
		   utils_validation \
		   newcolor \
		   lexe

vpath %.c	$(SRCS_PATH) \
		$(SRCS_PATH)/parser \
		$(SRCS_PATH)/display \
		$(SRCS_PATH)/utils

SOURCES		:= $(addsuffix .c, $(SRCS))
OBJECTS		:= $(patsubst %.c, $(OBJS_PATH)/%.o, $(SOURCES))

################################################################################
#                                  Makefile  objs                               #
################################################################################

DEF_COLOR	:= \033[0;39m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
CYAN		:= \033[0;96m

all: $(NAME)

$(OBJS_PATH)/%.o: %.c | $(OBJS_PATH)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBS) $(OBJECTS)
	@echo "$(GREEN)Creating executable...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBS) $(LIBS_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) is ready!$(DEF_COLOR)"

$(LIBS):
	@echo "$(BLUE)Creating libraries...$(DEF_COLOR)"
	@$(MAKE) -C ./libft
	@if [ ! -d "./MLX42/.git" ]; then \
		echo "$(BLUE)Initializing MLX42...$(DEF_COLOR)"; \
		git submodule update --init --recursive; \
	fi
	@cmake ./MLX42 -B ./MLX42/build
	@make -C ./MLX42/build -j4

$(OBJS_PATH):
	@echo "$(YELLOW)Creating objects directory...$(DEF_COLOR)"
	@mkdir -p $(OBJS_PATH)

################################################################################
#                                 PROGRAM'S RULES                               #
################################################################################

valgrind: CFLAGS += -O3
valgrind: re
	valgrind --leak-check=full --suppressions=mlx42.supp ./$(NAME) map/test.cub

clean:
	@echo "$(CYAN)Removing object files...$(DEF_COLOR)"
	@rm -rf $(OBJS_PATH)
	@rm -rf ./MLX42/build
	@$(MAKE) clean -C ./libft

fclean: clean
	@echo "$(CYAN)Removing executable...$(DEF_COLOR)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re valgrind

################################################################################