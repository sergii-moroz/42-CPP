NAME		=	serializer

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS		=	Data.cpp Serializer.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
