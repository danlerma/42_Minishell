# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 10:12:01 by dlerma-c          #+#    #+#              #
#    Updated: 2022/03/02 18:23:11 by dlerma-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#··············································································#
#                                   NAMES                                      #
#··············································································#

NAME = minishell

#··············································································#
#                                    PATH                                      #
#··············································································#

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = inc
LBFT_PATH = lbft

#··············································································#
#                                    LIBS                                      #
#··············································································#

# flags librerias
# ruta .a
LDFLAGS = -L $(LBFT_PATH)
LDFLAGS += "-L/Users/$(USER)/.brew/opt/readline/lib"
# nombre lib
LDLIBS = -lft
LDLIBS += -lreadline
#··············································································#
#                                    SRCS                                      #
#··············································································#

SRCS_PARSE_PATH = parse
SRCS_EXE_PATH = execute
SRCS_BUILT_PATH = built

SRCS_PARSE = nodes_set_data.c free_data.c \
			nodes_utils.c nodes_create_rework.c parse_str.c split_data_lst_rework.c
SRCS_EXE = execute.c make_process.c show_list.c commands.c init.c files.c \
			utils.c here.c lst.c lst_env.c utils_env.c
SRCS_BUILT = cd.c export.c env.c unset.c
SRCS = main.c
SRCS_NAME = $(addprefix $(SRCS_PARSE_PATH)/, $(SRCS_PARSE)) \
			$(addprefix $(SRCS_EXE_PATH)/, $(SRCS_EXE)) \
			$(addprefix $(SRCS_BUILT_PATH)/, $(SRCS_BUILT)) \
			$(SRCS)

OBJS_NAME_PATH = $(SRCS_PARSE_PATH) $(SRCS_EXE_PATH) $(SRCS_BUILT_PATH)
OBJS_PATH = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME_PATH))
OBJS_NAME = $(SRCS_NAME:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

#··············································································#
#                                    FLAGS                                     #
#··············································································#

CC = gcc
# CFLAGS =  -Wall -Werror -Wextra  -g3 
#include <xx.h> // path of .h
CFLAGS += -I $(INC_PATH) -I $(LBFT_PATH) -I /Users/$(USER)/.brew/opt/readline/include 
CFLAGS +="-I/Users/$(USER)/.brew/opt/readline/include"
#··············································································#
#                                    RULES                                     #
#··············································································#

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LBFT_PATH)
	$(CC) $^ -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJ_PATH) $(OBJS_PATH)

$(OBJ_PATH): 
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJS_PATH): 
	mkdir -p $(OBJS_PATH)

clean:
	make fclean -C $(LBFT_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
