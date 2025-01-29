CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -g
LDFLAGS		= -L$(LIBFT_DIR) -lft
RM			= rm -rf

SRCS_DIR	= src
BSRCS_DIR	= checker
OBJS_DIR	= obj
BOBJS_DIR	= checker_obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
HEAD		= inc

SRCS		= $(wildcard $(SRCS_DIR)/*.c)
BSRCS		= $(wildcard $(BSRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BOBJS		= $(patsubst $(BSRCS_DIR)/%.c, $(BOBJS_DIR)/%.o, $(BSRCS))

NAME		= push_swap
BNAME		= my_checker

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(BNAME)

$(BNAME):	$(BOBJS) $(LIBFT)
			$(CC) $(BOBJS) -o $@ $(LDFLAGS)

$(BOBJS_DIR)/%.o:	$(BSRCS_DIR)/%.c
			@mkdir -p $(BOBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling Objs..."

$(LIBFT):
			@echo "Building libft"
			@make all bonus -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS_DIR)
			$(RM) $(BOBJS_DIR)
			@echo "Cleaning libft"
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(BNAME)
			@echo "Fcleaning libft"
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(SRCS) $(OBJS)
