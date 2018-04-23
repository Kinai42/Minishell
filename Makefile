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

CC_FLAG++	?=	-O1 -g -fsanitize=address\
			-fno-omit-frame-pointer\

INCLUDE = include
PROJECT = Minishell
NAME = minishell

SRC		= $(SRC_W)

OBJ		:= $(notdir $(SRC:.c=.o))

OBJ_P		= $(addprefix $(P_OBJ)/,$(OBJ))

__START: os all
	printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./libft
	@make library --no-print-directory
	@$(CC) $(CC_FLAG) libft/libft.a -o $(NAME) $(OBJ_P) -l termcap

clean:
	make -C	./libft clean
	rm -f	$(OBJ_W)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

fclean: clean
	make -C ./libft fclean
	rm -f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed all binary ./$(P_BIN)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

re: fclean all

object:	$(SRC) $(P_SRC) $(P_OBJ)
	$(foreach SOURCE, $(SRC), \
	$(CC) $(CC_FLAG) -I$(P_INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
	printf "$(OK)[+][$(PROJECT)] $(SOURCE)$(C_DEF)" && \
	printf "\r\033[K" \
	;)
	printf "$(OK)[+][$(PROJECT)] Objects are made in ./$(P_OBJ)$(C_DEF)\n"

library: object $(P_OBJ) $(OBJ_P)
