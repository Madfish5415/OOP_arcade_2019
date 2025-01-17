##
## EPITECH PROJECT, 2019
## OOP_arcade_2019
## File description:
## Makefile
##

NAME				=		lib_arcade_pacman
LIB_NAME			=		lib_arcade_pacman.so
LIB_ST_NAME			=		lib_arcade_pacman.a
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		src
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests
ENGINE_DIR			= 		../../../engine

AR					=		ar rcs
CC					=		g++ -std=c++17
RM					=		rm -rf

MAIN_SRC			=		main.cpp

PROJ_SRC			=		../../game/AGame.cpp						\
							game/Game.cpp								\
							component/AI.cpp							\
							component/User.cpp							\
							system/AI.cpp								\
							system/User.cpp								\
							create.cpp									\
							#$(ENGINE_DIR)/component/AAudio.cpp			\
							$(ENGINE_DIR)/component/Animations.cpp		\
							$(ENGINE_DIR)/component/ARender.cpp			\
							$(ENGINE_DIR)/component/AText.cpp			\
							$(ENGINE_DIR)/component/AAI.cpp				\
							$(ENGINE_DIR)/component/AUser.cpp			\
							$(ENGINE_DIR)/component/Transform.cpp		\
							$(ENGINE_DIR)/component/Hitbox.cpp			\
							$(ENGINE_DIR)/component/Motion.cpp			\
							$(ENGINE_DIR)/component/Size.cpp			\
							$(ENGINE_DIR)/ecs/AComponent.cpp			\
							$(ENGINE_DIR)/ecs/ASystem.cpp				\
							$(ENGINE_DIR)/ecs/Entity.cpp				\
							$(ENGINE_DIR)/ecs/Universe.cpp				\
							$(ENGINE_DIR)/ecs/World.cpp					\
							$(ENGINE_DIR)/event/Close.cpp				\
							$(ENGINE_DIR)/event/Input.cpp				\
							$(ENGINE_DIR)/event/Collision.cpp			\
							$(ENGINE_DIR)/eventbus/AEvent.cpp			\
							$(ENGINE_DIR)/eventbus/EventBus.cpp			\
							$(ENGINE_DIR)/system/AAnimations.cpp		\
							$(ENGINE_DIR)/system/AAudio.cpp				\
							$(ENGINE_DIR)/system/ARender.cpp			\
							$(ENGINE_DIR)/system/AUser.cpp				\
							$(ENGINE_DIR)/system/AAI.cpp				\
							$(ENGINE_DIR)/system/Movement.cpp			\
							$(ENGINE_DIR)/system/Physics.cpp			\
							$(ENGINE_DIR)/type/Animation.cpp			\
							$(ENGINE_DIR)/type/Vector2D.cpp				\

TEST_SRC			=

CFLAGS				+=		-I $(INCL_DIR)
CFLAGS				+=		-W -Wall -Wextra -Werror

MAIN_OBJ			=		$(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

sweet:				all clean

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

debug_sweet:		CFLAGS += -g3
debug_sweet:		sweet

$(LIB_NAME):		CFLAGS += -fPIC
$(LIB_NAME):		LDFLAGS += -shared -rdynamic
$(LIB_NAME):		$(PROJ_OBJ)
					$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(LIB_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib:				$(LIB_NAME)

lib_clean:
					$(RM) $(PROJ_OBJ)

lib_fclean:			lib_clean
					$(RM) $(LIB_NAME)

lib_re:				lib_fclean lib

lib_sweet:			lib lib_clean

lib_debug:			CFLAGS += -g3
lib_debug:			lib

$(LIB_ST_NAME):		$(PROJ_OBJ)
					$(AR) $(LIB_ST_NAME) $(PROJ_OBJ) \
					&& echo "$(GREEN_B_COLOR)$(LIB_ST_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_ST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_st:				$(LIB_ST_NAME)

lib_st_clean:		lib_clean

lib_st_fclean:		lib_st_clean
					$(RM) $(LIB_ST_NAME)

lib_st_re:			lib_st_fclean lib_st

lib_st_sweet:		lib_st lib_st_clean

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sweet:		tests_run tests_clean

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

full:				all lib lib_st

full_clean:			clean lib_clean lib_st_clean tests_clean

full_fclean:		fclean lib_fclean lib_st_fclean tests_fclean

full_re:			re lib_re lib_st_re

full_sweet:			sweet lib_sweet lib_st_sweet

.PHONY:				all clean fclean re sweet											\
					debug debug_re debug_sweet											\
					lib lib_clean lib_fclean lib_re lib_sweet lib_debug					\
					lib_st lib_st_clean lib_st_fclean lib_st_re lib_st_sweet			\
					tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
					full full_clean full_fclean full_re full_sweet						\
