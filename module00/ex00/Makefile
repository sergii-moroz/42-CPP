NAME		=	megaphone

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				g++ $(CPPFLAGS) $(OBJS) -o $@

%.o:			%.cpp
				g++ -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

test1:
				./$(NAME)
test2:
				./$(NAME) "shhhhh... I think the students are asleep..."
test3:
				./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

re: fclean all

.PHONY: all clean fclean re test1 test2 test3