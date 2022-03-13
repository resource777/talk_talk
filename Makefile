CFLAGC = -Wall -Wextra -Werror
CC = gcc
src = minitalk_utils1.c minitalk_utils2.c
obj=$(src:.c=.o)
server = server
client = client
NAME = minitalk

all: $(NAME)
   	
$(NAME): $(server) $(client)
$(server):$(obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(obj) -o $(server)
$(client):$(obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(obj)
fclean: clean
	rm -rf $(client) $(server)
re: fclean all
