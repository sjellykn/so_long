NAME = libft.a

SRC = ft_memset.c	\
	  ft_bzero.c	\
	  ft_memcpy.c	\
	  ft_memccpy.c	\
	  ft_memmove.c	\
	  ft_memchr.c	\
	  ft_memcmp.c	\
	  ft_strlen.c	\
	  ft_strlcpy.c	\
	  ft_strlcat.c	\
	  ft_strchr.c	\
	  ft_strrchr.c	\
	  ft_strnstr.c	\
	  ft_strncmp.c	\
	  ft_atoi.c		\
	  ft_isalpha.c	\
	  ft_isdigit.c	\
	  ft_isalnum.c	\
	  ft_isascii.c	\
	  ft_isprint.c	\
	  ft_toupper.c	\
	  ft_tolower.c	\
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strmapi.c \
	  ft_itoa.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_putstr.c \
	  ft_strcmp.c 


FILEO = $(SRC:.c=.o)

HEADER = libft.h

WWW = -Wall -Werror -Wextra

%.o:	%.c
	gcc $(WWW) -c $< -o $@

all: $(NAME)

$(NAME): ${FILEO} ${HEADER}
	ar rcs $(NAME) $(FILEO) $?


clean:
	rm -f $(FILEO)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY	:	all clean fclean re bonus
