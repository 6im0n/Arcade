NAME =  arcade

NAME_PACMAN = lib/arcade_pacman.so

NAME_SNAKE = lib/arcade_snake.so

NAME_NCURSES = lib/arcade_ncurses.so

NAME_SFML = lib/arcade_sfml.so

NAME_SDL = lib/arcade_sdl.so

SRC =	core/main.cpp \

PACMAN_SRC =	lib/pacman/pacman.cpp \

SNAKE_SRC =		lib/snake/snake.cpp \

NCURSES_SRC =	lib/ncurses/ncurses.cpp \

SFML_SRC =		lib/sfml/sfml.cpp \

SDL_SRC =		lib/sdl/sdl.cpp \

SRC_TEST =	tests/test.cpp \

OBJ = $(SRC:.cpp=.o)
OBJ_PACMAN = $(PACMAN_SRC:.cpp=.o)
OBJ_SNAKE = $(SNAKE_SRC:.cpp=.o)
OBJ_NCURSES = $(NCURSES_SRC:.cpp=.o)
OBJ_SFML = $(SFML_SRC:.cpp=.o)
OBJ_SDL = $(SDL_SRC:.cpp=.o)
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++20 -I./include

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_PACMAN) $(OBJ_SNAKE) $(OBJ_NCURSES) $(OBJ_SFML) $(OBJ_SDL)
	g++ -std=c++20 -Wall -Wextra -Werror -o $(NAME) $(OBJ)
	g++ -shared -o $(NAME_PACMAN) $(OBJ_PACMAN)
	g++ -shared -o $(NAME_SNAKE) $(OBJ_SNAKE)
	g++ -shared -o $(NAME_NCURSES) $(OBJ_NCURSES) -lncurses
	g++ -shared -o $(NAME_SFML) $(OBJ_SFML) -lsfml-graphics -lsfml-window -lsfml-system
	g++ -shared -o $(NAME_SDL) $(OBJ_SDL) -lSDL2 -lSDL2_image -lSDL2_ttf

core : $(OBJ)
	g++ -std=c++20 -Wall -Wextra -Werror -o $(NAME) $(OBJ)

game : $(OBJ_PACMAN) $(OBJ_SNAKE)
	g++ -shared -o $(NAME_PACMAN) $(OBJ_PACMAN)
	g++ -shared -o $(NAME_SNAKE) $(OBJ_SNAKE)

graphicals : $(OBJ_NCURSES) $(OBJ_SFML) $(OBJ_SDL)
	g++ -shared -o $(NAME_NCURSES) $(OBJ_NCURSES) -lncurses
	g++ -shared -o $(NAME_SFML) $(OBJ_SFML) -lsfml-graphics -lsfml-window -lsfml-system
	g++ -shared -o $(NAME_SDL) $(OBJ_SDL) -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_PACMAN)
	rm -f $(OBJ_SNAKE)
	rm -f $(OBJ_NCURSES)
	rm -f $(OBJ_SFML)
	rm -f $(OBJ_SDL)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_PACMAN)
	rm -f $(NAME_SNAKE)
	rm -f $(NAME_NCURSES)
	rm -f $(NAME_SFML)
	rm -f $(NAME_SDL)

tests_fclean:
	rm -f $(OBJ_TEST)
	rm -f unit_tests
	rm -f unit_tests-main.gcda
	rm -f unit_tests-main.gcno

re: fclean all

tests_run: re
	g++ -o unit_tests $(SRC) $(CXXFLAGS) -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
