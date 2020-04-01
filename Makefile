##
## EPITECH PROJECT, 2019
## OOP_arcade_2019
## File description:
## Makefile
##

CD					=			cd
CP					=			cp
RM					=			rm -rf
MAKE				=			make

DIR_CORE			=			./core
BIN_CORE			=			arcade

DIR_LIB_SDL			=			./lib/sdl
BIN_LIB_SDL			=			lib_arcade_sdl2.so
DIR_LIB_SFML		=			./lib/sfml
BIN_LIB_SFML		=			lib_arcade_sfml.so
DIR_LIB_NCURSES		=			./lib/ncurses
BIN_LIB_NCURSES		=			lib_arcade_ncurses.so

DIR_GAME_PACMAN		=			./games/pacman
BIN_GAME_PACMAN		=			lib_arcade_pacman.so
DIR_GAME_NIBBLER	=			./games/nibbler
BIN_GAME_NIBBLER	=			lib_arcade_nibbler.so

all:		core games graphicals

core:
			$(CD) $(DIR_CORE) && $(MAKE)
			$(CP) $(DIR_CORE)/$(BIN_CORE) ./

graphicals:
			$(CD) $(DIR_LIB_SDL) && $(MAKE) lib
			$(CD) $(DIR_LIB_SFML) && $(MAKE) lib
			$(CD) $(DIR_LIB_NCURSES) && $(MAKE) lib
			$(CP) $(DIR_LIB_SDL)/$(BIN_LIB_SDL) ./lib/
			$(CP) $(DIR_LIB_SFML)/$(BIN_LIB_SFML) ./lib/
			$(CP) $(DIR_LIB_NCURSES)/$(BIN_LIB_NCURSES) ./lib/

games:
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) lib
			$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) lib
			$(CP) $(DIR_GAME_PACMAN)/$(BIN_GAME_PACMAN) ./
			$(CP) $(DIR_GAME_NIBBLER)/$(BIN_GAME_NIBBLER) ./

clean:
			$(CD) $(DIR_CORE) && $(MAKE) clean
			$(CD) $(DIR_LIB_SDL) && $(MAKE) clean
			$(CD) $(DIR_LIB_SFML) && $(MAKE) clean
			$(CD) $(DIR_LIB_NCURSES) && $(MAKE) clean
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) clean
			$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) clean

fclean:
			$(CD) $(DIR_CORE) && $(MAKE) fclean
			$(CD) $(DIR_LIB_SDL) && $(MAKE) fclean
			$(CD) $(DIR_LIB_SFML) && $(MAKE) fclean
			$(CD) $(DIR_LIB_NCURSES) && $(MAKE) fclean
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) fclean
			$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) fclean

re:			fclean all