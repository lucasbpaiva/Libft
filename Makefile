# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 21:23:41 by lbalderr          #+#    #+#              #
#    Updated: 2026/06/20 12:01:41 by lbalderr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/libc/ft_isalpha.c \
		  srcs/libc/ft_isdigit.c \
		  srcs/libc/ft_isalnum.c \
		  srcs/libc/ft_isascii.c \
		  srcs/libc/ft_isprint.c \
		  srcs/libc/ft_strlen.c \
		  srcs/libc/ft_memset.c \
		  srcs/libc/ft_bzero.c \
		  srcs/libc/ft_memcpy.c \
		  srcs/libc/ft_memmove.c \
		  srcs/libc/ft_strlcpy.c \
		  srcs/libc/ft_strlcat.c \
		  srcs/libc/ft_toupper.c \
		  srcs/libc/ft_tolower.c \
		  srcs/libc/ft_strchr.c \
		  srcs/libc/ft_strrchr.c \
		  srcs/libc/ft_strncmp.c \
		  srcs/libc/ft_memchr.c \
		  srcs/libc/ft_memcmp.c \
		  srcs/libc/ft_strnstr.c \
		  srcs/libc/ft_atoi.c \
		  srcs/additional/ft_calloc.c \
		  srcs/additional/ft_strdup.c \
		  srcs/additional/ft_substr.c \
		  srcs/additional/ft_strjoin.c \
		  srcs/additional/ft_strtrim.c \
		  srcs/additional/ft_split.c \
		  srcs/additional/ft_itoa.c \
		  srcs/additional/ft_strmapi.c \
		  srcs/additional/ft_striteri.c \
		  srcs/additional/ft_putchar_fd.c \
		  srcs/additional/ft_putstr_fd.c \
		  srcs/additional/ft_putendl_fd.c \
		  srcs/additional/ft_putnbr_fd.c \
		  srcs/linked_list/ft_lstnew.c \
		  srcs/linked_list/ft_lstadd_front.c \
		  srcs/linked_list/ft_lstsize.c \
		  srcs/linked_list/ft_lstlast.c \
		  srcs/linked_list/ft_lstadd_back.c \
		  srcs/linked_list/ft_lstdelone.c \
		  srcs/linked_list/ft_lstclear.c \
		  srcs/linked_list/ft_lstiter.c \
		  srcs/linked_list/ft_lstmap.c \
		  srcs/ft_printf/ft_dispatch.c \
		  srcs/ft_printf/ft_print_char.c \
		  srcs/ft_printf/ft_print_hex.c \
		  srcs/ft_printf/ft_print_int.c \
		  srcs/ft_printf/ft_print_ptr.c \
		  srcs/ft_printf/ft_print_str.c \
		  srcs/ft_printf/ft_print_uint.c \
		  srcs/ft_printf/ft_printf.c \

OBJS	= $(SRCS:.c=.o)
INCS	= includes
NAME	= libft.a
srcs/LIBC	= ar rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(srcs/LIBC) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
