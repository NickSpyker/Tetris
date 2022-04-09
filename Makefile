##
## EPITECH PROJECT, 2021
## B-PSU-200-MPL-2-1-tetris-clarisse.eynard
## File description:
## Makefile
##

######## COLORS #########

REDDARK		=    \033[31;1m
RED			=    \033[31;1m
GREEN  		=    \033[32;1m
YEL    		=    \033[33;1m
BLUE   		=    \033[34;1m
PINK   		=    \033[35;1m
CYAN   		=    \033[36;1m
WHITE  		=    \033[0m

#########################

BIN			= 	tetris

SRC			= 	main.c \
				$(wildcard ./src/*.c) \
				$(wildcard ./src/debug/*.c) \
				$(wildcard ./src/tetris/*.c) \
				$(wildcard ./src/graphic/*.c) \

OBJ			= 	$(SRC:.c=.o)

LIB			= 	./lib/libmy.a

CFLAGS		= 	-I./include -lncurses
LIBFLAGS	= 	-lmy -L./lib
BUGFLAGS    = 	-g3 -Werror -Wall -Wextra

DEBUG = no
ifeq ($(DEBUG), yes)
		CFLAGS += $(BUGFLAGS)
endif
ifeq ($(DEBUG), g3)
		CFLAGS += -g3
endif

all : $(BIN) clean
	@ echo "$(GREEN)BUILD SUCCESS!$(WHITE)"

$(BIN) : $(LIB) $(OBJ)
	@ gcc -o $(BIN) $(OBJ) $(CFLAGS) $(LIBFLAGS)
	@ echo "$(WHITE)[$(GREEN)BUILD BIN$(WHITE)] OBJ\n\t ➜  \
	$(CYAN)BIN ./$@$(WHITE)"

$(LIB) :
	@ make -C ./lib/my --no-print-directory

%.o : %.c
	@ echo "$(WHITE)[$(GREEN)BUILD$(WHITE)]     $<$(WHITE)"
	@ gcc $(CFLAGS) -o $@ -c $<
	@ echo "[$(GREEN)√$(WHITE)]\t ➜  $(CYAN)$@$(WHITE)"

re : fclean all

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ echo "\e[1;32mCleaning ..."
	@ rm -rf $(BIN)
	@ make -C ./lib/my/ clean --no-print-directory
