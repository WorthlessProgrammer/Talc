NAME=talc
OUT=NAME 
CC=g++ 
FLAGS=-Wall -Wextra -std=c++20
LINKS=-lm

$(NAME):
	$(CC) $(LINKS) $(FLAGS) $(NAME).cpp -o $(NAME)

clear:
	rm $(NAME)

re:
	clear $(NAME)
