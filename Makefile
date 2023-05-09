# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 16:49:21 by joestrad          #+#    #+#              #
#    Updated: 2023/02/14 17:43:46 by joestrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

SRCS =  check_input1.c check_input2.c list_int_utils1.c \
	   list_int_utils2.c list_int_utils3.c manage_index.c push_operations.c \
	   swap_operations.c rotate_operations1.c rotate_operations2.c calc_costs.c \
	   sort_utils1.c sort_utils2.c sort_utils3.c

INC_LFT = -Ilibft

BSRCS = checker.c list_oper_utils.c chk_operations.c \
		gnl/get_next_line.c

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

GREEN = "\033[32m"

RED = "\033[31m"

NOCOLOR = "\033[0m"

%.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) push_swap.c $(SRCS) -o $(NAME)
	@echo $(GREEN)Program push_swap ready$(NOCOLOR)

all: $(NAME) $(NAMEB)

$(NAMEB): $(LIBFT) $(OBJS) $(BOBJS)
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) $(SRCS) $(BSRCS) -o $(NAMEB)
	@echo $(GREEN)Program checker ready$(NOCOLOR)

$(LIBFT):
	@make -C libft --silent
	@make bonus -C libft --silent
	@echo $(GREEN)Libft ready$(NOCOLOR)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BOBJS)
	@make clean -C libft --silent
	@echo Objects files $(RED)cleaned$(NOCOLOR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEB)
	@$(RM) $(LIBFT)
	@echo Executables files $(RED)cleaned$(NOCOLOR)

re: fclean all
	@echo $(RED)Cleaned$(NOCOLOR) and $(GREEN)rebuilt$(NOCOLOR) push_swap project


py100: all
	python3 python_visualizer.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

py500: all
	python3 python_visualizer.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re
