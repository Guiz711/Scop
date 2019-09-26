# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:56:40 by gmichaud          #+#    #+#              #
#    Updated: 2019/09/26 18:54:04 by gmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftmath.a

INC_FLAGS = -I./includes

INC_NAME = libftmath.h

INC_PATH = ./includes

SRC_PATH = src

SRC_NAME = float_op.c vec_init.c \
	vec2_op1.c vec2_op2.c vec3_op1.c vec3_op2.c vec4_op1.c vec4_op2.c  \
	matrices.c matrices_op.c quaternions.c quaternions_op.c projection.c

CC = clang

CFLAGS = -Wall -Wextra -Werror -O3

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

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "\n$(BLU)[$(NAME)]$(GRN) Compilation success$(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<
	@echo "\r$(ERASE)$(BLU)[$(NAME)]$(RESET) $@ created\c"

clean:
	@/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(BLU)[$(NAME)]$(RED) .o files deleted$()$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo  "$(BLU)[$(NAME)]$(RED) executable file deleted$(RESET)"

re: fclean $(NAME)
