NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_ = 
SRCS = $(addsuffix .c, $(SRCS_))
BONUS = $(addsuffix .c, $(BONUS_))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

ifeq ($(MAKECMDGOALS),bonus)
OBJS += $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all
	
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus