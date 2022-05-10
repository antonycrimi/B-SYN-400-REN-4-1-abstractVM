##
## EPITECH PROJECT
## Makefile AbstractVM
## File description:
## Makefile
##

ECHO 		=	/bin/echo -e

SRCDIR		=	src/

SRC			=	$(SRCDIR)Chipset/chipset.cpp	\
				$(SRCDIR)Types/Int8.cpp	\
				$(SRCDIR)Types/Int16.cpp	\
				$(SRCDIR)Types/Int32.cpp	\
				$(SRCDIR)Types/Float.cpp	\
				$(SRCDIR)Types/Double.cpp	\
				$(SRCDIR)Types/BigDecimal.cpp	\
				$(SRCDIR)CPU/cpu.cpp	\
				$(SRCDIR)IO/io.cpp	\
				$(SRCDIR)Memory/memory.cpp	\
				$(SRCDIR)Main/main.cpp 		\

NAME		=	abstractVM

OBJ 		= 	$(SRC:.cpp=.o)

CXXFLAGS	+= 	-std=c++14 -Wall -g3 -I includes/

all:		title $(NAME)

title:
		@$(ECHO) BUILDING $(NAME)

$(NAME): 	$(OBJ)
	@g++ $(CXXFLAGS) -o $(NAME) $(OBJ) &&  \
	$(ECHO) COMPILING $(OBJ)

clean:
	@$(RM) $(OBJ) \
	&& $(ECHO) "<< CLEANING >>" $(OBJ)

fclean: clean
	@$(RM) $(NAME) && $(ECHO) "<< CLEANING >>" $(NAME)

re: fclean all
