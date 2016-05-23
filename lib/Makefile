##
## Makefile for Makefile in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
## 
## Made by Korial
## Login   <korial@epitech.net>
## 
## Started on  Tue May 10 19:20:54 2016 Korial
## Last update Mon May 23 19:46:47 2016 Korial
##

COLOR		= \x1b[32;01m

COLOR_OFF	= \x1b[0m

PROG_OK		= $(COLOR)[SDL2 compiled]$(COLOR_OFF)

CC		= g++

RM		= rm -f

NAME		= MapGenerator.so

SRC		= src/MapGenerator.cpp \
		  src/MgUtils.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -fPIC -W -Wall -Wextra -std=c++11 -I./include 

LDFLAGS		= $(SDL_LIB) -shared

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		@echo -e "$(PROG_OK)"

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all
