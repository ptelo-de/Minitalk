
NAME= libft.a
SERVER_NAME = server
CLIENT_NAME= client
all: $(NAME) $(SERVER_NAME) $(CLIENT_NAME)
$(NAME):
	make bonus -C ./libft
$(SERVER_NAME):
	cc -Wall -Wextra -Werror server.c  ./libft/libft.a -o server
$(CLIENT_NAME):
	cc -Wall -Wextra -Werror client.c  ./libft/libft.a -o client

clean:
	make clean -C ./libft
fclean:
	make fclean -C ./libft
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
re: fclean all


 