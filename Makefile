# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:33:41 by qestefan          #+#    #+#              #
#    Updated: 2022/02/17 11:46:01 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

INC_DIR = philo/includes
SRC_DIR = philo/source
OBJ_DIR = philo/objects
ROOT_FOLDER = philo/

INC_DIR_BONUS = philo_bonus/includes
SRC_DIR_BONUS = philo_bonus/source
OBJ_DIR_BONUS = philo_bonus/objects
ROOT_FOLDER_BONUS = philo_bonus/

HEADERS = $(wildcard $(INC_DIR)/*.h)
SRCS	= $(wildcard $(SRC_DIR)/*.c)
vpath %.c $(SRC_DIR)
OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

HEADERS_BONUS = $(wildcard $(INC_DIR_BONUS)/*.h)
SRCS_BONUS	= $(wildcard $(SRC_DIR_BONUS)/*.c)
vpath %.c $(SRC_DIR_BONUS)
OBJS_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(notdir $(SRCS_BONUS:.c=.o)))

all : $(NAME)

bonus: $(NAME_BONUS)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(RM) $(RMFLAGS) $(OBJ_DIR_BONUS)
	@printf "Delete object files\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(addprefix $(ROOT_FOLDER)/, $(NAME))
	@$(RM) $(RMFLAGS) $(addprefix $(ROOT_FOLDER_BONUS)/, $(NAME_BONUS))
	@printf "Delete $(NAME) $(NAME_BONUS)\n"

re : fclean all

norm :
	norminette philo philo_bonus

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(HEADERS) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR)  -c $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $(addprefix $(ROOT_FOLDER)/, $(NAME))
	@printf "Successfully created $@\n"

$(OBJ_DIR_BONUS) :
	@mkdir $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)/%.o : %.c $(OBJ_DIR_BONUS) $(HEADERS_BONUS)
	@$(CC) $(CFLAGS) -I $(INC_DIR_BONUS) -c $< -o $@

$(NAME_BONUS) : $(HEADERS_BONUS) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -I $(INC_DIR_BONUS) $(OBJS_BONUS) -o $(addprefix $(ROOT_FOLDER_BONUS)/, $(NAME_BONUS))
	@printf "Successfully created $@\n"

PHONY: all bonus clean fclean re norm
