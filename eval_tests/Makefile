# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:26:33 by swilliam          #+#    #+#              #
#    Updated: 2022/08/03 16:23:18 by swilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

EXECUTABLE = test

HEADER = ../includes

LIBFT_FOLDER = ../Libft/src/
LIBFT_FILES = ft_strcmp ft_strncmp ft_strdup ft_strlen ft_toupper ft_tolower \
ft_strstr ft_strnstr ft_strchr ft_strrchr ft_strcpy ft_strncpy ft_strcat \
ft_strncat ft_strlcat ft_isdigit ft_isascii ft_isalpha ft_isalnum ft_isprint \
ft_atoi ft_putchar ft_putstr ft_putnbr ft_putendl ft_strequ ft_strnequ \
ft_memset ft_bzero ft_memchr ft_memcpy ft_memccpy ft_memcmp ft_memmove \
ft_striter ft_striteri ft_memalloc ft_strnew ft_strclr ft_memdel ft_strdel \
ft_strmap ft_strmapi ft_itoa ft_strjoin ft_putchar_fd ft_putendl_fd \
ft_putnbr_fd ft_putstr_fd ft_strtrim ft_strsub ft_strsplit ft_lstadd \
ft_lstnew ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_isoddspace \
ft_iswhitespace ft_arrdel ft_wordcount ft_strrev ft_lstlen

LIBFT_SOURCE_FILES = $(patsubst %, $(LIBFT_FOLDER)%.c, $(LIBFT_FILES))
LIBFT_OBJECTS = $(patsubst %, %.o, $(LIBFT_FILES))

FT_PRINTF_FOLDER = ../src/
FT_PRINTF_FILES = \
ft_printf \
print_char print_integer print_string print_octal \
print_decimal print_hexadecimal print_float_f \
length_modifier_c \
length_modifier_di \
length_modifier_f \
length_modifier_o \
length_modifier_u \
length_modifier_x \
length_modifier_s \
length_modifier_p \
ft_printf_error ft_printf_flags ft_printf_unsigned_utilities \
ft_printf_signed_utilities ft_printf_float_f_utilities

FT_PRINTF_SOURCE_FILES = $(patsubst %, $(FT_PRINTF_FOLDER)%.c, $(FT_PRINTF_FILES))
FT_PRINTF_OBJECTS = $(patsubst %, %.o, $(FT_PRINTF_FILES))

FLAGS = -Wall -Wextra -Werror
ADD_LIBFT = -L. $(NAME)

all: 		$(NAME)

$(NAME): 	$(SOURCE_FILES)
			make -sC ../libft/
			gcc -c $(FLAGS) $(LIBFT_SOURCE_FILES) -I $(HEADER)
			gcc -c $(FLAGS) $(FT_PRINTF_SOURCE_FILES) -I$(HEADER)
			ar rc $(NAME) $(LIBFT_OBJECTS) $(FT_PRINTF_OBJECTS)
			ranlib $(NAME)
			gcc $(FLAGS) $(ADD_LIBFT) -I$(HEADER) main.c -o $(EXECUTABLE)

clean:
			rm -f $(LIBFT_OBJECTS) $(FT_PRINTF_OBJECTS)
			make clean -sC ../libft/

fclean: 	clean
			rm -f $(NAME) $(EXECUTABLE)
			make fclean -sC ../libft/

re:			fclean all

.PHONY: all clean fclean re