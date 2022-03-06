NAME = pipex

BNAME = pipex_bonus

LIBPATH = libft/

LIB = libft/libft.a

HEADERS = pipex.h get_next_line.h

SRCS = pipex.c utils.c findqoutes.c joinarg.c remqoutes.c getpath.c error.c

BSRCS = pipex_bonus.c utils.c utils_bonus.c get_next_line.c findqoutes.c joinarg.c remqoutes.c getpath.c error.c

LSRCS = $(addprefix libft/src/, ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_striteri.c)

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:%.c=%.o)

LOBJS = $(LSRCS:%.c=%.o)

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(LIB) $(OBJS) $(HEADERS)
	cc -Wall -Wextra -Werror $(OBJS) $(LIB) -o $(NAME)

$(BNAME): $(LIB) $(BOBJS) $(HEADERS)
	cc -Wall -Wextra -Werror $(BOBJS) $(LIB) -o $(BNAME)

$(LIB): $(LOBJS) libft/libft.h
	make -C $(LIBPATH)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)
	make -C $(LIBPATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)
	make -C $(LIBPATH) fclean
	
re: fclean all