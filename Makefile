# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbalderr <lbalderr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 21:23:41 by lbalderr          #+#    #+#              #
#    Updated: 2026/06/19 17:58:18 by lbalderr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= libc/ft_isalpha.c \
		  libc/ft_isdigit.c \
		  libc/ft_isalnum.c \
		  libc/ft_isascii.c \
		  libc/ft_isprint.c \
		  libc/ft_strlen.c \
		  libc/ft_memset.c \
		  libc/ft_bzero.c \
		  libc/ft_memcpy.c \
		  libc/ft_memmove.c \
		  libc/ft_strlcpy.c \
		  libc/ft_strlcat.c \
		  libc/ft_toupper.c \
		  libc/ft_tolower.c \
		  libc/ft_strchr.c \
		  libc/ft_strrchr.c \
		  libc/ft_strncmp.c \
		  libc/ft_memchr.c \
		  libc/ft_memcmp.c \
		  libc/ft_strnstr.c \
		  libc/ft_atoi.c \
		  additional/ft_calloc.c \
		  additional/ft_strdup.c \
		  additional/ft_substr.c \
		  additional/ft_strjoin.c \
		  additional/ft_strtrim.c \
		  additional/ft_split.c \
		  additional/ft_itoa.c \
		  additional/ft_strmapi.c \
		  additional/ft_striteri.c \
		  additional/ft_putchar_fd.c \
		  additional/ft_putstr_fd.c \
		  additional/ft_putendl_fd.c \
		  additional/ft_putnbr_fd.c \
		  linked_list/ft_lstnew.c \
		  linked_list/ft_lstadd_front.c \
		  linked_list/ft_lstsize.c \
		  linked_list/ft_lstlast.c \
		  linked_list/ft_lstadd_back.c \
		  linked_list/ft_lstdelone.c \
		  linked_list/ft_lstclear.c \
		  linked_list/ft_lstiter.c \
		  linked_list/ft_lstmap.c

OBJS	= $(SRCS:.c=.o)
INCS	= includes
NAME	= libft.a
LIBC	= ar rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
