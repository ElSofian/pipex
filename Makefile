# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/06 18:06:26 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = pipex
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRCS		= src/main.c src/pipes.c src/utils.c src/errors.c libft/libft.a

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

all: $(NAME)

$(NAME): dependencies
	@touch input.txt
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN)[Success]$(END_COLOR) Pipex is ready !"

dependencies:
	@make -s -C libft
	
clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean: clean
	@$(RM) bin $(NAME) input.txt output.txt
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted !"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done !"

.PHONY: all clean fclean re
