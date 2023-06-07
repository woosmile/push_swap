NAME = libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra
AR = ar
ARFLAGS = rcs
RM = rm
RMFLAGS = -rf

MANDATORY_SRCS = \
ft_strlen.c \
ft_strdup.c \
ft_split.c \
ft_strncmp.c \
ft_calloc.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MANDATORY_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(MANDATORY_OBJS) : $(MANDATORY_SRCS)
	$(CC) $(CFLAGS) -c $(MANDATORY_SRCS)

clean :
	$(RM) $(RMFLAGS) $(MANDATORY_OBJS)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : fclean all

.PHONY : all clean fclean re