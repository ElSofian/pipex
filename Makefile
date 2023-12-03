# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/03 17:45:55 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = pipex.a
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS		= src/main.c

OBJ_DIR     = bin
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


# **************************************************************************** #
# COLORS

GREEN       = \033[0;32m
GREY        = \033[1;30m
PURPLE      = \033[0;35m
BLUE        = \033[0;94m
CYAN        = \033[0;35m
PINK        = \033[0;35m
END_COLOR   = \033[0;39m


# **************************************************************************** #
# RULES

dependencies:
	@make -s -C libft
	@make -s all

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)[Success]$(END_COLOR) Pipex is ready!"
	@$(CC) $(CFLAGS) $(OBJS) -I inc $(LIBFT) -o pipex

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I inc -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean: clean
	@$(RM) bin $(NAME) pipex
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted !"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done !"

.PHONY: all clean fclean re
