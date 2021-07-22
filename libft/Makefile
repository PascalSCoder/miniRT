# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pascal <pascal@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/02 15:18:24 by pascal        #+#    #+#                  #
#    Updated: 2021/03/31 19:28:28 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
LIBFT_C		=	ft_memccpy.c	ft_atoi.c		ft_split.c\
				ft_itoa.c		ft_memcmp.c		ft_strmapi.c\
				ft_putchar_fd.c	ft_bzero.c		ft_calloc.c\
				ft_memcpy.c		ft_strlen.c		ft_strjoin.c\
				ft_strncmp.c	ft_strdup.c		ft_isascii.c\
				ft_tolower.c	ft_strchr.c		ft_toupper.c\
				ft_strrchr.c	ft_strlcat.c	ft_isalnum.c\
				ft_memmove.c	ft_memchr.c		ft_isprint.c\
				ft_putstr_fd.c	ft_putendl_fd.c	ft_isalpha.c\
				ft_strlcpy.c	ft_strnstr.c	ft_substr.c\
				ft_strtrim.c	ft_isdigit.c	ft_memset.c\
				ft_putnbr_fd.c
LIBFT_O		=	$(LIBFT_C:.c=.o)
EXT_DIR		=	libft_ext
EXT_C		=	ft_absllnum.c		ft_decitohex.c\
				ft_iswhitespace.c	ft_memdup.c\
				ft_power.c			ft_strnjoin.c\
				ft_strtolower.c		ft_strtoupper.c\
				ft_ulltoa.c			ft_split_set.c\
				ft_charcmpset.c		ft_atof.c\
				ft_strcmp.c			ft_split_free.c
EXT_O		=	$(EXT_C:%.c=$(EXT_DIR)/%.o)
CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc

all: $(NAME)

$(NAME): $(LIBFT_O) $(EXT_O)
	ar -crs $(NAME) $(LIBFT_O) $(EXT_O)

$(EXT_DIR)/%.o: $(EXT_DIR)/%.c $(EXT_DIR)/libft_ext.h libft.h
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.c libft.h
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIBFT_O) $(EXT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
