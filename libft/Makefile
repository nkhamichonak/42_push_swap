# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 11:20:11 by nkhamich          #+#    #+#              #
#    Updated: 2024/12/02 12:33:30 by nkhamich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRC			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

SRC_BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_PRINTF	= printf/ft_printf.c printf/ft_print_char.c printf/ft_print_hex.c \
				printf/flag_utils.c printf/ft_print_int.c printf/ft_print_pointer.c \
				printf/ft_print_string.c printf/ft_print_unsigned.c \
				printf/ft_parse_flags.c printf/print_utils.c

SRC_GNL		= gnl/get_next_line.c gnl/get_next_line_utils.c gnl/get_next_line_bonus.c \
				gnl/get_next_line_utils_bonus.c

OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS   = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
OBJ_PRINTF  = $(SRC_PRINTF:%.c=$(OBJ_DIR)/%.o)
OBJ_GNL  	= $(SRC_GNL:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Object directory created for $(NAME)."

$(NAME): $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)
	@ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)
	@echo "$(NAME) library created successfully."

bonus: all

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo "Object files cleaned for $(NAME)."; \
	fi

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) library fully cleaned."

re: fclean all

.PHONY: all bonus clean fclean re
