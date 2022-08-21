NAME = libftprintf.a

LIBFTDIR = ./libft
OBJDIR = ./objs

SRCS_ = ft_printf\
		print_str_char\
		num_to_arr\
		print_num_arr\
		flags

SRCS = $(addsuffix .c, $(SRCS_))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o:	%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

bonus: all

clean:
	make clean -C $(LIBFTDIR)
	rm -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus