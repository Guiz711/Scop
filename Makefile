# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 14:03:15 by jgourdin          #+#    #+#              #
#    Updated: 2019/03/29 12:10:04 by gmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

SRC_NAME = error.c shader.c shader_error.c keytable_alloc.c keytable_update.c \
	keytable_utils.c init_env.c init_scene.c loop.c inputs.c main.c

INC_NAME = scop.h shader.h error.h

INC_PATH = ./includes

INC_FLAGS = -I./includes -I./libft/includes -I./libftmath/includes \
	-I./minilibx_macos -I./mlxext/includes

LIB_FLAGS = -L./libft -L./libftmath -L./minilibx_macos \
	-L/System/Library/Frameworks

LIBS = -lft -lftmath -lmlx -lm -framework OpenGL -framework Appkit

CC = clang

CFLAGS = -g #-Wall -Wextra -Werror

SRC_PATH = src

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC:.c=.o)

OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(OBJ_NAME))

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

RED = \x1B[31m
GRN = \x1B[32m
YEL = \x1B[33m
BLU = \x1B[34m
MAG = \x1B[35m
CYN = \x1B[36m
WHT = \x1B[37m
RESET = \x1B[0m
ERASE = \033[2K

all: $(NAME)

libftmake:
	@make -C ./libft --no-print-directory

mlxmake:
	@make -C ./minilibx_macos --no-print-directory

libftmathmake:
	@make -C ./libftmath --no-print-directory

$(NAME): $(OBJ) | libftmake libftmathmake mlxmake 
	@$(CC) -o $@ $(OBJ) $(LIB_FLAGS) $(LIBS)
	@echo "$(BLU)[$(NAME)]$(GRN) Compilation success$(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $< 
	@echo "$(BLU)[$(NAME)]$(RESET) $@ created"

clean:
	@/bin/rm -f $(OBJ) 2> /dev/null || true
	@/bin/rm -r $(OBJ_PATH) 2> /dev/null || true
	@echo "$(BLU)[$(NAME)]$(RED) .o files deleted$(RESET)"
	@make -C ./libft clean --no-print-directory
	@make -C ./libftmath clean --no-print-directory
	@make -C ./minilibx_macos clean --no-print-directory

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LINKNAME)
	@echo  "$(BLU)[$(NAME)]$(RED) executable file deleted$(RESET)"
	@make -C ./libft fclean --no-print-directory
	@make -C ./libftmath fclean --no-print-directory
	@make -C ./minilibx_macos fclean --no-print-directory

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
