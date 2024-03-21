##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Arcade Makefile
##

#Program Name
NAME 		 	= arcade
NAME_PACMAN  	= lib/arcade_pacman.so
NAME_SNAKE 	 	= lib/arcade_snake.so
NAME_NCURSES 	= lib/arcade_ncurses.so
NAME_SFML 	 	= lib/arcade_sfml.so
NAME_SDL 	 	= lib/arcade_sdl.so

#Sources
SRC_CORE      	= core/main.cpp \
		          core/DLLoader.cpp \
				  core/Core.cpp \

PACMAN_SRC   	= lib/pacman/pacman.cpp \

SNAKE_SRC =		lib/snake/Entities/Color.cpp		\
				lib/snake/Entities/Void.cpp			\
				lib/snake/Entities/Wall.cpp			\
				lib/snake/Entities/SnakeBody.cpp	\
				lib/snake/Entities/Food.cpp			\
				lib/snake/SnakeGame.cpp				\
				lib/snake/Snake.cpp					\

NCURSES_SRC  	= lib/ncurses/ncurses.cpp \

SFML_SRC     	= lib/sfml/sfml.cpp \

SDL_SRC      	= lib/sdl/sdl.cpp \

SRC_TEST     	= tests/testDLLoader.cpp \
			      core/DLLoader.cpp \

#Objects
OBJ_CORE		= $(SRC_CORE:.cpp=.o)
OBJ_PACMAN		= $(PACMAN_SRC:.cpp=.o)
OBJ_SNAKE		= $(SNAKE_SRC:.cpp=.o)
OBJ_NCURSES		= $(NCURSES_SRC:.cpp=.o)
OBJ_SFML		= $(SFML_SRC:.cpp=.o)
OBJ_SDL			= $(SDL_SRC:.cpp=.o)

#flags
CXXFLAGS		= -g -fno-gnu-unique -Wall -Wextra -Werror -std=c++20 -fPIC
SFML_FlAGS		= -lsfml-graphics -lsfml-window -lsfml-system
SDL_FLAGS		= -lSDL2 -lSDL2_image -lSDL2_ttf
NCURSES_FLAGS	= -lncurses
INC				= -I.

#Compiler
CC				= g++
LINKER			= g++

#Colors
GREEN 			= /bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW 			= /bin/echo -e "\x1b[33m $1\x1b[0m"

#Rules
all: $(NAME) $(NAME_PACMAN) $(NAME_SNAKE) $(NAME_NCURSES) $(NAME_SFML) $(NAME_SDL)

%.o: 	%.cpp
	@$(CC) $(INC) $(CXXFLAGS) -c -o $@ $< && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

$(NAME) : $(OBJ_CORE)
	@$(LINKER) -o $(NAME) $(OBJ_CORE) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_PACMAN) : $(OBJ_PACMAN)
	@$(LINKER) -shared -o $(NAME_PACMAN) $(OBJ_PACMAN) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SNAKE) : $(OBJ_SNAKE)
	@$(LINKER) -shared -o $(NAME_SNAKE) $(OBJ_SNAKE) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_NCURSES) : $(OBJ_NCURSES)
	@$(LINKER) -shared -o $(NAME_NCURSES) $(OBJ_NCURSES) $(CXXFLAGS) $(NCURSES_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SFML) : $(OBJ_SFML)
	@$(LINKER) -shared -o $(NAME_SFML) $(OBJ_SFML) $(CXXFLAGS) $(SFML_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SDL) : $(OBJ_SDL)
	@$(LINKER) -shared -o $(NAME_SDL) $(OBJ_SDL) $(CXXFLAGS) $(SDL_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

clean:
	@rm -f $(OBJ_CORE)
	@rm -f $(OBJ_PACMAN)
	@rm -f $(OBJ_SNAKE)
	@rm -f $(OBJ_NCURSES)
	@rm -f $(OBJ_SFML)
	@rm -f $(OBJ_SDL)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_PACMAN)
	@rm -f $(NAME_SNAKE)
	@rm -f $(NAME_NCURSES)
	@rm -f $(NAME_SFML)
	@rm -f $(NAME_SDL)
	@$(call GREEN,"✅ [$@] done !")

tests_fclean: fclean
	rm -f $(OBJ_TEST)
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno

re: fclean all

tests_run: re
	g++ -o unit_tests $(SRC_TEST) $(CXXFLAGS) -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
