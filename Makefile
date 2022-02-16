##
## EPITECH PROJECT, 2021
## cpppool
## File description:
## Makefile
##

CC		= g++

CFLAGS	= -std=c++20 -Wall -Wextra -Werror

SRC		= $(wildcard *.cpp)

OBJ 	= $(SRC:.cpp=.o)

OUT		= my_cat

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $(SRC)

clean:
	$(RM) -rf $(OBJ)

fclean:	clean
	$(RM) $(OUT)

re: fclean all
