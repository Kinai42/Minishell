# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 12:30:56 by dbauduin          #+#    #+#              #
#    Updated: 2018/05/09 02:50:32 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include .misc/make/color
include .misc/make/paths
include .misc/make/misc_var

.SILENT	: __START	NAME	clean fclean all re object library os_dep libft
.PHONY	: __START			clean fclean all re object library os_dep libft


.DEFAULT_GOAL = __START

CC		?=	clang
CC_FLAG ?=		-Werror\
			-Wall\
			-Wextra\
			# -O1 -g -fsanitize=address	\
			# -fno-omit-frame-pointer		\
			# -fsanitize-address-use-after-scope \


#CC_FLAG++	?=	-O1 -g -fsanitize=address\
			-fno-omit-frame-pointer\


CC_FLAG++	?= -ggdb

INCLUDE = include
PROJECT = Minishell
NAME = minishell

SRC		=	src/main.c\
			src/cd.c\
			src/env.c\
			src/exec.c\
			src/ft_array.c\
			src/ft_stdin.c\
			src/other.c\
			src/other2.c\
			src/other3.c\
			src/setup.c\
			src/termcaps.c

OBJ		:= $(notdir $(SRC:.c=.o))

OBJ_P		= $(addprefix $(P_OBJ)/,$(OBJ))

__START: os all
	printf "$(OK)[+] $(C_DEF)[$(PROJECT)]$(OK) Done$(C_DEF)\n"

all: $(NAME)

$(NAME): $(SRC) $(MAIN)
	@make -C ./libft
	@$(CC) $(MAIN) $(SRC) $(CC_FLAG) -l termcap -I include -I libft/include --include ./libft/include/printf.h  -L libft -lft  -o $(NAME)  

clean:
	make -C	./libft clean
	printf	"$(WARN)[!] $(C_DEF)[$(PROJECT)]$(WARN) Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+] $(C_DEF)[$(PROJECT)]$(OK) Cleaned$(C_DEF)\n"

fclean: clean
	make -C ./libft fclean
	rm -f	$(NAME)
	printf	"$(WARN)[!] $(C_DEF)[$(PROJECT)]$(WARN) Removed all binary ./$(P_BIN)$(C_DEF)\n"
	printf	"$(OK)[+] $(C_DEF)[$(PROJECT)]$(OK) Fully cleaned$(C_DEF)\n"

re: fclean __START
