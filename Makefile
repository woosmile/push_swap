NAME = push_swap

CC = cc
CFLAGS = -Werror -Wall -Wextra
MAKE = make
MFLAGS = -C
RM = rm
RMFLAGS = -rf

LIBFT_DIR = libft
LIBFT_SRCS = \
libft/ft_strlen.c \
libft/ft_strdup.c \
libft/ft_split.c \
libft/ft_strncmp.c \
libft/ft_calloc.c
LIBFT_LIB = libft.a

MANDATORY_SRCS = \
push_swap_argv_check.c \
push_swap_edited_libft.c \
push_swap_lis.c \
push_swap_op_five_under.c \
push_swap_op_main.c \
push_swap_op1.c \
push_swap_op2.c \
push_swap_op3.c \
push_swap_op4.c \
push_swap_rotate_cycle.c \
push_swap_rotate_stack.c \
push_swap_search_node.c \
push_swap_utils.c \
push_swap.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_DIR = bonus
BONUS_SRCS = \
bonus/checker_argv_check_bonus.c \
bonus/checker_bonus.c \
bonus/checker_edited_libft_bonus.c \
bonus/checker_op_main_bonus.c \
bonus/checker_op1_bonus.c \
bonus/checker_op2_bonus.c \
bonus/checker_op3_bonus.c \
bonus/checker_op4_bonus.c \
bonus/checker_utils_bonus.c
BONUS = $(BONUS_DIR)/checker

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(MANDATORY_OBJS) $(LIBFT_SRCS)
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) -L./libft -lft

$(BONUS) : $(BONUS_SRCS) $(LIBFT_SRCS)
	$(MAKE) $(MFLAGS) $(BONUS_DIR) all

$(MANDATORY_OBJS) : $(MANDATORY_SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) clean
	$(MAKE) $(MFLAGS) $(BONUS_DIR) clean
	$(RM) $(RMFLAGS) $(MANDATORY_OBJS)

fclean : clean
	$(MAKE) $(MFLAGS) $(LIBFT_DIR) fclean
	$(MAKE) $(MFLAGS) $(BONUS_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re