SRCS =	main.cpp\
		Contact.cpp\
		PhoneBook.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .cpp.o
