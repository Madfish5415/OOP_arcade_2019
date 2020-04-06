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

MAKEFLAGS			+=		--silent

all:		games graphicals core

core:
			$(CD) $(DIR_CORE) && $(MAKE)
			$(CP) $(DIR_CORE)/$(BIN_CORE) ./

graphicals:
			$(CD) $(DIR_LIB_SDL) && $(MAKE) lib
			$(CD) $(DIR_LIB_SFML) && $(MAKE) lib
			#$(CD) $(DIR_LIB_NCURSES) && $(MAKE) lib
			$(CP) $(DIR_LIB_SDL)/$(BIN_LIB_SDL) ./lib/
			$(CP) $(DIR_LIB_SFML)/$(BIN_LIB_SFML) ./lib/
			#$(CP) $(DIR_LIB_NCURSES)/$(BIN_LIB_NCURSES) ./lib/

games:
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) lib
			#$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) lib
			$(CP) $(DIR_GAME_PACMAN)/$(BIN_GAME_PACMAN) ./games/
			#$(CP) $(DIR_GAME_NIBBLER)/$(BIN_GAME_NIBBLER) ./games/

clean:
			$(CD) $(DIR_CORE) && $(MAKE) clean
			$(CD) $(DIR_LIB_SDL) && $(MAKE) lib_clean
			$(CD) $(DIR_LIB_SFML) && $(MAKE) lib_clean
			#$(CD) $(DIR_LIB_NCURSES) && $(MAKE) lib_clean
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) lib_clean
			#$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) lib_clean

fclean:
			$(CD) $(DIR_CORE) && $(MAKE) fclean
			$(CD) $(DIR_LIB_SDL) && $(MAKE) lib_fclean
			$(CD) $(DIR_LIB_SFML) && $(MAKE) lib_fclean
			#$(CD) $(DIR_LIB_NCURSES) && $(MAKE) lib_fclean
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) lib_fclean
			#$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) lib_fclean

debug:
			$(CD) $(DIR_LIB_SDL) && $(MAKE) lib_debug
			$(CD) $(DIR_LIB_SFML) && $(MAKE) lib_debug
			#$(CD) $(DIR_LIB_NCURSES) && $(MAKE) lib_debug
			$(CP) $(DIR_LIB_SDL)/$(BIN_LIB_SDL) ./lib/
			$(CP) $(DIR_LIB_SFML)/$(BIN_LIB_SFML) ./lib/
			#$(CP) $(DIR_LIB_NCURSES)/$(BIN_LIB_NCURSES) ./lib/
			$(CD) $(DIR_GAME_PACMAN) && $(MAKE) lib_debug
			#$(CD) $(DIR_GAME_NIBBLER) && $(MAKE) lib_debug
			$(CP) $(DIR_GAME_PACMAN)/$(BIN_GAME_PACMAN) ./games/
			#$(CP) $(DIR_GAME_NIBBLER)/$(BIN_GAME_NIBBLER) ./games/
			$(CD) $(DIR_CORE) && $(MAKE) debug
			$(CP) $(DIR_CORE)/$(BIN_CORE) ./

re:			fclean all

tests_sh:
			echo "OK"

tests_run:
			$(CD) $(DIR_CORE) && $(MAKE) tests_run

tests_clean:
			$(CD) $(DIR_CORE) && $(MAKE) tests_clean

tests_fclean:
			$(CD) $(DIR_CORE) && $(MAKE) tests_fclean

.PHONY: all core graphicals games debug re tests_sh tests_run tests_clean tests_fclean