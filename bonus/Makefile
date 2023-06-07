NAME = ../checker

CC = cc
CFLAGS = -Werror -Wall -Wextra
MAKE = make
MFLAGS = -C
RM = rm
RMFLAGS = -rf

LIBFT_DIR = ../libft
LIBFT_SRCS = \
../libft/ft_strlen.c \
../libft/ft_strdup.c \
../libft/ft_split.c \
../libft/ft_strncmp.c \
../libft/ft_calloc.c
LIBFT_LIB = libft.a

BONUS_SRCS = \
checker_argv_check_bonus.c \
checker_bonus.c \
checker_edited_libft_bonus.c \
checker_op_main_bonus.c \
checker_op1_bonus.c \
checker_op2_bonus.c \
checker_op3_bonus.c \
checker_op4_bonus.c \
checker_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(BONUS_OBJS) $(LIBFT_SRCS)
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) -L../libft -lft

$(BONUS_OBJS) : $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(BONUS_OBJS)

fclean : clean
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re