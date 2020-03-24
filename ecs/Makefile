##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile.
##


NAME			=		a.out
LIB_NAME		=		libstring.a
TEST_NAME		=		tests/unit_tests

NO_COLOR		=		\e[0;0m
GREEN_COLOR		=		\e[0;32m
RED_COLOR		=		\e[0;31m
GREEN_B_COLOR	=		\e[1;32m
RED_B_COLOR		=		\e[1;31m

AR				=		ar rc
CC				=		g++
RM				=		rm -rf

MAIN_SRC		=		main.cpp

PROJ_SRC		=		

TEST_SRC		=

MAIN_OBJ		=		$(MAIN_SRC:.cpp=.o)

PROJ_OBJ		=		$(PROJ_SRC:.cpp=.o)

TEST_OBJ		=		$(TEST_SRC:.cpp=.o)

TEST_COV		=		$(PROJ_SRC:.cpp=.gcda)	\
						$(PROJ_SRC:.cpp=.gcno)	\
						$(TEST_SRC:.cpp=.gcda)	\
						$(TEST_SRC:.cpp=.gcno)	\


INCLUDE_DIR		=		"./"

CFLAGS			+=		-W -Wall -Wextra -Werror

MAKEFLAGS		+=		--silent

%.o:			%.cpp
				$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
				&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
				|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }



all:			$(NAME)

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)


re:				fclean all

sweet:			all clean

debug:			CFLAGS += -g3
debug:			sweet

tests_run:		TEST_FLAG += -fprofile-arcs -ftest-coverage --coverage
tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage --coverage
tests_run:		LDLIBS += -lgcov -lcriterion
tests_run:		$(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }
				$(TEST_NAME) \
				&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; }

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run
				gcovr
				gcovr -b --exclude tests/
				make tests_clean

.PHONY:			all clean fclean re main main_clean main_fclean main_re sweet sweet_lib debug tests_run tests_clean tests_fclean tests_re tests_sweet