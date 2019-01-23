# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 14:03:15 by jgourdin          #+#    #+#              #
#    Updated: 2019/01/23 14:46:29 by gmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

INC_FLAGS = -I./includes -I./libft/includes -I./minilibx_macos -I./mlxext/includes

INC_NAME = scop.h shader.h error.h

INC_PATH = ./includes

LIB_FLAGS = -L./libft -L./minilibx_macos -L/System/Library/Frameworks

LIBS = -lft -lmlx -lm -framework OpenGL -framework Appkit

CC = clang

CFLAGS = #-Wall -Wextra -Werror

SRC_PATH = src

SRC_NAME = error.c shader.c shader_error.c main.c 

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC:.c=.o)

OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(OBJ_NAME))

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

GREEN = \033[32m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./minilibx_macos --no-print-directory
	@make -C ./libft --no-print-directory
	@$(CC) -o $@ $(OBJ) $(LIB_FLAGS) $(LIBS)
	@echo "$(GREEN)[$(NAME)] Compilation success"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c #$(INC)
	@mkdir -p $(OBJ_PATH) #2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $< 

clean:
	@/bin/rm -f $(OBJ) 2> /dev/null || true
	@/bin/rm -r $(OBJ_PATH) 2> /dev/null || true
	@echo "$(GREEN)[$(NAME)] .o files deleted"
	@make -C ./libft clean --no-print-directory
	@make -C ./minilibx_macos clean --no-print-directory

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LINKNAME)
	@echo  "$(GREEN)[$(NAME)] executable file deleted"
	@make -C ./libft fclean --no-print-directory
	@make -C ./minilibx_macos fclean --no-print-directory

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
