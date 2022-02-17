# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:33:41 by qestefan          #+#    #+#              #
#    Updated: 2022/02/16 11:04:06 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang
CFLAGS = -Wall -Werror -Wextra
RM = rm
RMFLAGS = -rf

INC_DIR = philo/includes
SRC_DIR = philo/source
OBJ_DIR = philo/objects
MAND_DIR = philo

HEADERS = $(wildcard $(INC_DIR)/*.h)
SRCS	= $(wildcard $(SRC_DIR)/*.c)
vpath %.c $(SRC_DIR)
OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "Deleted $(NAME)'s object files\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(addprefix $(MAND_DIR)/, $(NAME))
	@printf "Deleted $(NAME)\n"

re : fclean all

norm :
	norminette philo philo_bonus

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(HEADERS) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR)  -c $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $(addprefix $(MAND_DIR)/, $(NAME))
	@printf "Successfully Created\n"

PHONY: all clean fclean re norm
