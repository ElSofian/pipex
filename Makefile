# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/04 10:46:37 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = pipex
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS		= src/main.c src/utils.c src/pipes.c src/errors.c libft/libft.a

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
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean: clean
	@$(RM) bin $(NAME)
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted !"

re: fclean dependencies
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done !"

.PHONY: all clean fclean re
