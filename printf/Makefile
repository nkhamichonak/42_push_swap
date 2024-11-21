# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natallia <natallia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 11:20:11 by nkhamich          #+#    #+#              #
#    Updated: 2024/10/31 20:05:34 by natallia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
SRC			= ft_printf.c ft_print_char.c ft_print_hex.c \
				ft_print_int.c ft_print_pointer.c ft_print_string.c \
				ft_print_unsigned.c ft_parse_flags.c print_utils.c\
				flag_utils.c
OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Object directory created for $(NAME)."

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(NAME) library created successfully."

$(LIBFT):
	@make -C $(LIBFT_PATH) all

bonus: $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned for $(NAME)."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
	@echo "$(NAME) library fully cleaned."

re: fclean all

.PHONY: all bonus clean fclean re libft
