all:
	@gcc -o rat -D BUFFER_SIZE=42 main.c libft.a
clean:
	@rm rat
