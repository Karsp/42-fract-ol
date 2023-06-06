# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 17:55:22 by daviles-          #+#    #+#              #
#    Updated: 2023/06/05 12:52:33 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

INCLUDE = libft.h

SRC = ft_isprint.c ft_memmove.c ft_strrchr.c \
	  ft_bzero.c ft_memset.c ft_tolower.c\
	  ft_isalnum.c ft_strchr.c ft_toupper.c \
	  ft_isalpha.c ft_strlcpy.c ft_isascii.c \
	  ft_memchr.c ft_strlen.c ft_isdigit.c \
	  ft_memcpy.c ft_strncmp.c ft_strlcat.c \
	  ft_strnstr.c ft_memcmp.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c

BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c ft_lstlast_bonus.c \
	   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c

PRINTF	=	./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c

OBJ = $(SRC:.c=.o) $(PRINTF:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC	= gcc 

CFLAGS = -Wall -Wextra -Werror 

AR = ar rcs

RM = rm -f


all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)


bonus :	$(OBJ) $(BOBJ) 
	$(AR) -r $(NAME) $?

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ) 
	$(RM) $(BOBJ)

fclean : clean
	$(RM) $(NAME)


re : fclean all

rebonus :	fclean bonus 

.PHONY : all NAME clean fclean re bonus rebonus
