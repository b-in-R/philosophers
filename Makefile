# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabiner <rabiner@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 12:28:22 by rabiner           #+#    #+#              #
#    Updated: 2025/05/16 18:48:31 by rabiner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
RM = rm -f
CFLAGS = -g #-Wall -Wextra -Werror

SRCS_DIR = srcs
SRCS =	philo.c parsing.c utils.c

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS_DIR = $(SRCS_DIR)/objs
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I.

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re