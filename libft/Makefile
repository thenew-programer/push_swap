SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			  ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
			  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c get_next_line.c

B_SRCS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

HEAD		= libft.h

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${B_SRCS:.c=.o}

NAME		= libft.a

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "Compiling Libft..."

all:		$(NAME)

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@echo "Libft Mandatory Compiled."

bonus:		${B_OBJS}
			@${AR} ${NAME} ${B_OBJS}
			@echo "Libft Bonus Compiled."

clean:
			@${RM} ${OBJS} ${B_OBJS}
			@echo "Cleaning Libft obj files."

fclean:		clean
			@${RM} $(NAME)
			@echo "Cleaning Libft exec files."

re:			fclean all
			@echo "Rebuild Libft."

.PHONY:		all bonus clean fclean re
