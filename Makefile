NAME=talc
OUT=NAME 
CC=g++
FLAGS=-Wall -Wextra
LINKS=-lm

$(NAME):
	$(CC) $(LINKS) $(FLAGS) $(NAME).cpp -o $(NAME)

clear:
	rm $(NAME)

re:
	clear $(NAME)
