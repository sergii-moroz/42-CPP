NAME	=	phoneBook

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS	=	Contact.class.cpp PhoneBook.class.cpp main.cpp
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

.PHONY: all clean fclean re
