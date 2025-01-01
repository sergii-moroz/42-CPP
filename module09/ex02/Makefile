NAME	=	PmergeMe

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -rf
SRCS	=	PmergeMe.cpp main.cpp
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.cpp PmergeMe.hpp PmergeMe.tpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:
			./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

test1:
			./PmergeMe 5 3 7 9 4 8 2 6

test2:
			./PmergeMe 5 3 4 1

test5:
			./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`
test10:
			./PmergeMe `shuf -i 1-100000 -n 10 | tr "\n" " "`
test50:
			./PmergeMe `shuf -i 1-100000 -n 50 | tr "\n" " "`
test100:
			./PmergeMe `shuf -i 1-100000 -n 100 | tr "\n" " "`
test500:
			./PmergeMe `shuf -i 1-100000 -n 500 | tr "\n" " "`
test3000:
			./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

.PHONY:		all clean fclean re
