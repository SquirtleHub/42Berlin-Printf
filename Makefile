# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    forealsazzeddi <sazzeddi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 13:56:21 by sazzeddi          #+#    #+#              #
#    Updated: 2022/12/08 13:56:22 by sazzeddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
NAMELFT := libft.a
sources :=  ft_printf.c ft_printf_utils.c
objects := $(sources:.c=.o)
LIBDIR := libft

all: $(NAME)

$(NAME): $(objects)
	make bonus -C $(LIBDIR)
	cp -v $(LIBDIR)/$(NAMELFT) $(NAME)
	ar cr $@ $^

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(objects)
	$(RM) *.o $(LIBDIR)/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBDIR)/$(NAMELFT)

re: fclean all
.PHONY: all clean fclean re
