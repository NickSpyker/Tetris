##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -g3

LIB_SRC = $(wildcard *.c) \

LIB_OBJ = $(LIB_SRC:.c=.o)

TARGET_LIB = libmy.a

all: $(TARGET_LIB)

$(TARGET_LIB): $(LIB_OBJ)
	@ ar src $(TARGET_LIB) $(LIB_OBJ)
	@ cp $(TARGET_LIB) ..

$(LIB_OBJ): $(LIB_SRC)
	@ $(CC) $(CFLAGS) -c $(LIB_SRC)

clean:
	@ rm -rf ../$(TARGET_LIB)
	@ rm -rf $(TARGET_LIB)
	@ rm -rf $(LIB_OBJ)
	@ rm -rf $(OBJ)
