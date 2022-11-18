all:
	@gcc -o rat -D BUFFER_SIZE=10000 main.c libft.a
clean:
	@rm rat
