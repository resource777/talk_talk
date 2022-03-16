# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewonki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 14:47:27 by jaewonki          #+#    #+#              #
#    Updated: 2022/03/16 16:22:31 by jaewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror
CC = gcc
src = minitalk_utils1.c minitalk_utils2.c
obj=$(src:.c=.o)
server = server
client = client
NAME = $(server) $(client) 
sersrc = server.c
clisrc = client.c
sobj = $(sersrc:.c=.o)
cobj = $(clisrc:.c=.o)

all: $(NAME)
   
$(server):$(obj) $(sobj) minitalk.h
	$(CC) $(CFLAGS) $(sobj) $(obj) -o $(server)
$(client):$(obj) $(cobj) minitalk.h
	$(CC) $(CFLAGS) $(cobj) $(obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(obj) $(sobj) $(cobj)
fclean: clean
	rm -rf $(NAME)
re: fclean all
