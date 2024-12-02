# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natallia <natallia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:03:26 by nkhamich          #+#    #+#              #
#    Updated: 2024/12/02 20:44:29 by natallia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRC			= main.c parse.c memory_ops.c utils.c instructions.c \
				mini_sort.c algorithm_main.c algorithm_math.c \
				algorithm_utils.c list_ops.c
SRC_BONUS	= checker_bonus/checker.c checker_bonus/checker_utils.c
OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS	= $(filter-out $(OBJ_DIR)/main.o, $(OBJ)) $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Object directory created for $(NAME)."

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(NAME) executable created successfully."

$(LIBFT):
	@make -C $(LIBFT_PATH) all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) executable created successfully."

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned for $(NAME)."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Executables fully cleaned."

re: fclean all

.PHONY: all bonus clean fclean re libft
