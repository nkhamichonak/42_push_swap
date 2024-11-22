# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 13:03:26 by nkhamich          #+#    #+#              #
#    Updated: 2024/11/22 16:51:06 by nkhamich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
SRC			= main.c parse.c free_stuff.c utils.c
OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

PRINTF_PATH = ./printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Object directory created for $(NAME)."

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@cp $(LIBFT) $(NAME)
	@cp $(PRINTF) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(NAME) library created successfully."

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@make -C $(LIBFT_PATH) bonus

$(PRINTF):
	@make -C $(PRINTF_PATH) all

bonus: $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned for $(NAME)."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME) a.out
	@echo "$(NAME) library fully cleaned."

re: fclean all

.PHONY: all bonus clean fclean re libft printf
