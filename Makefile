##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Arcade Makefile
##

#Program Name
NAME 		 	= arcade
NAME_CENTIPEDE  	= lib/arcade_centipede.so
NAME_SNAKE 	 	= lib/arcade_snake.so
NAME_NCURSES 	= lib/arcade_ncurses.so
NAME_SFML 	 	= lib/arcade_sfml.so
NAME_SDL 	 	= lib/arcade_sdl.so
NAME_VULKAN 	= lib/arcade_vulkan.so

#Sources
SRC_CORE      	= core/main.cpp \
		          core/DLLoader.cpp \
				  core/Core.cpp \
				  core/menu/Menu.cpp \
				  core/menu/Button.cpp \
				  abstract/AGame.cpp \
				  classes/Color.cpp \
				  classes/Text.cpp \

CENTIPEDE_SRC = 	src/centipede/Entities/Void.cpp			\
					src/centipede/Entities/Wall.cpp			\
					src/centipede/Entities/SnakeBody.cpp	\
					src/centipede/Entities/Player.cpp		\
					src/centipede/Entities/Bullet.cpp		\
					src/centipede/Score.cpp					\
					src/centipede/CentipedeGame.cpp			\
					src/centipede/Snake.cpp					\
					classes/Timer.cpp						\
					classes/Color.cpp						\
					abstract/AGame.cpp							\

SNAKE_SRC = 	src/snake/Entities/Void.cpp			\
				src/snake/Entities/Wall.cpp			\
				src/snake/Entities/SnakeBody.cpp	\
				src/snake/Entities/Food.cpp			\
				src/snake/Score.cpp					\
				src/snake/SnakeGame.cpp				\
				src/snake/Snake.cpp					\
				classes/Timer.cpp					\
				classes/Color.cpp					\
				abstract/AGame.cpp					\

NCURSES_SRC  	= src/ncurses/Ncurses.cpp \

SFML_SRC     	= src/sfml/Sfml.cpp \

SDL_SRC      	= src/sdl/Sdl.cpp \

VULKAN_SRC  	= src/vulkan/Vulkan.cpp \

SRC_TEST     	= tests/tests_color.cpp		\
				  classes/Color.cpp			\
				  tests/tests_timer.cpp		\
				  classes/Timer.cpp			\
				  tests/snake/Entities/tests_food.cpp		\
				  tests/snake/Entities/tests_void.cpp		\
				  tests/snake/Entities/tests_wall.cpp		\
				  tests/snake/Entities/tests_snake_body.cpp	\
				  tests/snake/tests_snake.cpp	\
				  tests/snake/tests_SnakeGame.cpp	\
				  src/snake/Entities/Food.cpp				\
				  src/snake/Entities/Wall.cpp				\
				  src/snake/Snake.cpp						\
				  src/snake/Score.cpp						\
				  src/snake/SnakeGame.cpp					\
				  src/snake/Entities/SnakeBody.cpp			\
				  src/snake/Entities/Void.cpp				\


#Objects
OBJ_CORE		= $(SRC_CORE:.cpp=.o)
OBJ_CENTIPEDE		= $(CENTIPEDE_SRC:.cpp=.o)
OBJ_SNAKE		= $(SNAKE_SRC:.cpp=.o)
OBJ_NCURSES		= $(NCURSES_SRC:.cpp=.o)
OBJ_SFML		= $(SFML_SRC:.cpp=.o)
OBJ_SDL			= $(SDL_SRC:.cpp=.o)
OBJ_TEST		= $(SRC_TEST:.cpp=.o)
OBJ_VULKAN		= $(VULKAN_SRC:.cpp=.o)

#GCDA & GCNO
GCDA_CORE		= $(SRC_CORE:.cpp=.gcda)
GCDA_CENTIPEDE		= $(CENTIPEDE_SRC:.cpp=.gcda)
GCDA_SNAKE		= $(SNAKE_SRC:.cpp=.gcda)
GCDA_NCURSES	= $(NCURSES_SRC:.cpp=.gcda)
GCDA_SFML		= $(SFML_SRC:.cpp=.gcda)
GCDA_SDL		= $(SDL_SRC:.cpp=.gcda)
GCDA_VULKAN		= $(VULKAN_SRC:.cpp=.gcda)
GCDA_TEST		= $(SRC_TEST:.cpp=.gcda)
GCDA_FILES		= $(GCDA_CORE) $(GCDA_CENTIPEDE) $(GCDA_SNAKE) $(GCDA_NCURSES) $(GCDA_SFML) $(GCDA_SDL) $(GCDA_TEST)
GCNO_CORE		= $(SRC_CORE:.cpp=.gcno)
GCNO_CENTIPEDE	= $(CENTIPEDE_SRC:.cpp=.gcno)
GCNO_SNAKE		= $(SNAKE_SRC:.cpp=.gcno)
GCNO_NCURSES	= $(NCURSES_SRC:.cpp=.gcno)
GCNO_SFML		= $(SFML_SRC:.cpp=.gcno)
GCNO_SDL		= $(SDL_SRC:.cpp=.gcno)
GCNO_VULKAN		= $(VULKAN_SRC:.cpp=.gcno)
GCNO_TEST		= $(SRC_TEST:.cpp=.gcno)
GCNO_FILES		= $(GCNO_CORE) $(GCNO_CENTIPEDE) $(GCNO_SNAKE) $(GCNO_NCURSES) $(GCNO_SFML) $(GCNO_SDL) $(GCNO_TEST)

#flags
CXXFLAGS		= -g -fno-gnu-unique -Wall -Wextra -Werror -std=c++20
CXXFLAGS 		+= -fprofile-arcs
SFML_FLAGS		= -lsfml-graphics -lsfml-window -lsfml-system
SDL_FLAGS		= -lSDL2 -lSDL2_image -lSDL2_ttf
VULKAN_FLAGS	= -lglfw
NCURSES_FLAGS	= -lncurses
INC				= -I.

#Compiler
CC				= g++
LINKER			= g++

#Colors
GREEN 			= /bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW 			= /bin/echo -e "\x1b[33m $1\x1b[0m"

#Rules
all: core games graphicals

#-----------------Games Rules--------------------

games: $(NAME_CENTIPEDE) $(NAME_SNAKE)

%.o: 	%.cpp
	@$(CC) $(INC) $(CXXFLAGS) -fPIC -c -o $@ $< && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

$(NAME_CENTIPEDE) : $(OBJ_CENTIPEDE)
	@$(LINKER) -shared -o $(NAME_CENTIPEDE) $(OBJ_CENTIPEDE) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SNAKE) : $(OBJ_SNAKE)
	@$(LINKER) -shared -fPIC  -o $(NAME_SNAKE) $(OBJ_SNAKE) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

#------------------Core Rules--------------------

core: $(NAME)

%.o: 	%.cpp
	@$(CC) $(INC) $(CXXFLAGS) -c -o $@ $< && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

$(NAME) : $(OBJ_CORE)
	@$(LINKER) -o $(NAME) $(OBJ_CORE) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

#-----------------Graphics Rules------------------

graphicals: $(NAME_NCURSES) $(NAME_SFML) $(NAME_SDL)

%.o: 	%.cpp
	@$(CC) $(INC) $(CXXFLAGS) -fPIC -c -o $@ $< && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

$(NAME_NCURSES) : $(OBJ_NCURSES)
	@$(LINKER) -shared -fPIC -o $(NAME_NCURSES) $(OBJ_NCURSES) $(CXXFLAGS) $(NCURSES_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SFML) : $(OBJ_SFML)
	@$(LINKER) -shared -fPIC -o $(NAME_SFML) $(OBJ_SFML) $(CXXFLAGS) $(SFML_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

$(NAME_SDL) : $(OBJ_SDL)
	@$(LINKER) -shared -fPIC -o $(NAME_SDL) $(OBJ_SDL) $(CXXFLAGS) $(SDL_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

clean:
	@rm -f $(OBJ_CORE)
	@rm -f $(OBJ_CENTIPEDE)
	@rm -f $(OBJ_SNAKE)
	@rm -f $(OBJ_NCURSES)
	@rm -f $(OBJ_SFML)
	@rm -f $(OBJ_SDL)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_CENTIPEDE)
	@rm -f $(NAME_SNAKE)
	@rm -f $(NAME_NCURSES)
	@rm -f $(NAME_SFML)
	@rm -f $(NAME_SDL)
	@$(call GREEN,"✅ [$@] done !")

tests_fclean:
	rm -f $(OBJ_TEST)
	rm -f $(NAME)
	rm -f unit_tests
	rm -f $(GCDA_FILES)
	rm -f $(GCNO_FILES)

re: fclean all

obj: $(OBJ_CORE) $(OBJ_CENTIPEDE) $(OBJ_SNAKE) $(OBJ_NCURSES) $(OBJ_SFML) $(OBJ_SDL)

tests_obj: $(OBJ_TEST)

tests_run: fclean
	$(MAKE) obj CXXFLAGS+=--coverage -lcriterion
	$(MAKE) tests_obj CXXFLAGS+=-lcriterion
	g++ -o unit_tests $(OBJ_TEST) $(CXXFLAGS) -lcriterion --coverage
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/
