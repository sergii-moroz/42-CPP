NAME	=	phoneBook

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS	=	Contact.cpp PhoneBook.cpp main.cpp
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			c++ $(CPPFLAGS) $(OBJS) -o $@

%.o:		%.cpp
			c++ -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
