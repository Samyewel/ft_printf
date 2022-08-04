# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:26:33 by swilliam          #+#    #+#              #
#    Updated: 2022/08/03 16:18:22 by swilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SOURCES = ft_strcmp.c ft_strncmp.c ft_strdup.c ft_strlen.c ft_toupper.c \
ft_tolower.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strcpy.c \
ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_isdigit.c ft_isascii.c \
ft_isalpha.c ft_isalnum.c ft_isprint.c ft_atoi.c ft_putchar.c ft_putstr.c \
ft_putnbr.c ft_putendl.c ft_strequ.c ft_strnequ.c ft_memset.c ft_bzero.c \
ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_striter.c \
ft_striteri.c ft_memalloc.c ft_strnew.c ft_strclr.c ft_memdel.c ft_strdel.c \
ft_strmap.c ft_strmapi.c ft_itoa.c ft_strjoin.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strtrim.c ft_strsub.c \
ft_strsplit.c ft_lstadd.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_isoddspace.c ft_iswhitespace.c ft_arrdel.c ft_wordcount.c \
get_next_line.c

SRC_DIR = ./src/
OBJECTS = $(addprefix	$(OBJ_DIR), $(SOURCES:.c=.o))
OBJ_DIR = ./objects/
HEADER = -I include

BLUE	= "\x1b[34m"

all: 		$(NAME)

$(NAME): 	$(OBJECTS)
			@ar rc $(NAME) $(OBJECTS)
			@echo $(BLUE) "Compiling libft..." $(EOC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
			@rm -f $(OBJECTS)
			@rm -rf $(OBJ_DIR)

fclean: 	clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re