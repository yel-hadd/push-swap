# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 20:23:25 by yel-hadd          #+#    #+#              #
#    Updated: 2023/03/11 23:14:48 by yel-hadd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = pushswap.h
SRC := main.c \
	utils/add_to_stack.c \
	utils/ft_strdup.c \
	utils/parse.c \
	utils/empty_arg.c \
	utils/ft_memset.c \
	utils/ft_bzero.c \
	utils/ft_calloc.c \
	utils/add_index.c \
	utils/ft_lstsize.c \
	utils/push_chunk.c \
	utils/count_words.c \
	utils/ft_memcmp.c \
	utils/reverse_rotate.c \
	utils/free_2d.c \
	utils/ft_memcpy.c \
	utils/rotate.c \
	utils/ft_atoi.c \
	utils/ft_strlen.c \
	utils/sort_five.c \
	utils/ft_before_last.c \
	utils/ft_strncmp.c \
	utils/sort_four.c \
	utils/ft_isdigit.c \
	utils/has_duplicates.c \
	utils/sort_gt_five.c \
	utils/ft_isspace.c \
	utils/has_errors.c \
	utils/sort_three.c \
	utils/ft_lstadd_back.c \
	utils/has_spaces.c \
	utils/split.c \
	utils/ft_lstadd_front.c \
	utils/is_sorted.c \
	utils/swap.c \
	utils/ft_lstclear.c \
	utils/master_filter.c \
	utils/top_or_buttom.c \
	utils/ft_lstlast.c \
	utils/push.c \
	utils/ft_lstnew.c \
	utils/push_back.c \

OBJ        := $(SRC:.c=.o)

%.o : %.c ${HEADER}
	${CC} -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	@cc -Wall -Werror -Wextra $(OBJ) -o push_swap

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus