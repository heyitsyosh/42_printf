NAME = libftprintf.a

LIBFTDIR = ./libft
OBJDIR = ./objs

SRCS_ = ft_printf\
		print_str_char\
		print_int_hex\
		ulltoa
BONUS_ = flags_bonus

SRCS = $(addsuffix .c, $(SRCS_))
BONUS = $(addsuffix .c, $(BONUS_))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft.h

ifeq ($(MAKECMDGOALS),bonus)
OBJS += $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o:	%.c
	@mkdir -p $(OBJDIR)
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