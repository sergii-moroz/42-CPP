NAME		=	array

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM			=	rm -rf

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:			%.cpp Array.hpp
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
