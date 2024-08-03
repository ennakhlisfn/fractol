# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 09:50:49 by sennakhl          #+#    #+#              #
#    Updated: 2024/06/01 11:37:25 by sennakhl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c errors.c drawing_img.c events.c math.c string_handling.c 
B_SOURCES = BONUS/main_bonus.c BONUS/errors_bonus.c BONUS/drawing_img_bonus.c BONUS/events_bonus.c BONUS/math_bonus.c BONUS/string_handling_bonus.c 

NAME = fractol
B_NAME = fractol_bonus
OBJECTS = $(SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror
LDFLAGS = -lmlx_Linux -lXext -lX11

all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

bonus: $(B_NAME)

$(B_NAME): $(B_OBJECTS)
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re
