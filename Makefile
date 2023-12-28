# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/14 12:53:24 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = pipex
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinc -g3
RM          = rm -rf

SRCS		= src/main.c src/utils.c src/errors.c
OBJS        = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_DIR    = bin

# **************************************************************************** #
# COLORS

GREEN       = \033[0;32m
GREY        = \033[1;30m
PURPLE      = \033[0;35m
BLUE        = \033[0;94m
CYAN        = \033[0;36m
PINK        = \033[1;35m
END_COLOR   = \033[0;39m


# **************************************************************************** #
# RULES

all: dependencies $(NAME)

$(NAME): $(OBJS)
	@touch input.txt
	@echo "Salut les mecs\nMoi c'est Sofian\nCa va ?" > input.txt
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[Success]$(END_COLOR) Pipex is ready !"

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

dependencies:
	@make -s -C libft

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted"

fclean: clean
	@$(RM) $(OBJS_DIR) $(NAME) input.txt output.txt src/*.o
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re