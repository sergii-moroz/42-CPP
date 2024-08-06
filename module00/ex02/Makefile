NAME	=	account

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS	=	Account.cpp tests.cpp
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			g++ $(CPPFLAGS) $(OBJS) -o $@

%.o:		%.cpp
			g++ -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

run:		all
			./account

.PHONY: all clean fclean re
