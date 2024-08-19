# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 09:15:02 by aylamgha          #+#    #+#              #
#    Updated: 2024/08/19 16:15:16 by aylamgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC= push_swap.c ft_split.c parsing.c conv_nums.c checkers.c printing.c utils.c commands.c commands_2.c push_swap_utils.c push_swap_utils_2.c

SRC_BONUS= $(SRC) checker_bonus.c get_next_line.c get_next_line_utils.c
OBJ_BONUS= $(SRC_BONUS:.c=.o)

OBJ= $(SRC:.c=.o)
NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror

NAME_BONUS= checker

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ) main.c
	$(CC) $(CFLAGS) $^ -o $(NAME) 

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -rf main.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BONUS)

re: fclean all

.PHONY: all NAME clean fclean re
