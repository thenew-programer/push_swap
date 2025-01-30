CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD) -g
LDFLAGS		= -L$(LIBFT_DIR) -lft
RM			= rm -rf

SRCS_DIR	= src
BSRCS_DIR	= bonus
OBJS_DIR	= obj
BOBJS_DIR	= bonus_obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
HEAD		= inc

MFILES		= algorithm.c command.c error.c main.c parser.c \
				stack_1.c stack_2.c utils_1.c utils_2.c
BFILES		= command.c error.c main.c parser.c sort.c \
			  stack_1.c stack_2.c utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(MFILES))
BSRCS		= $(addprefix $(BSRCS_DIR)/, $(BFILES))
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BOBJS		= $(patsubst $(BSRCS_DIR)/%.c, $(BOBJS_DIR)/%.o, $(BSRCS))

NAME		= push_swap
BNAME		= checker

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(OBJS) -o $@ $(LDFLAGS)
			@echo "$(NAME) compiled Successfully"

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $(NAME)..."

bonus:		$(BNAME)

$(BNAME):	$(BOBJS) $(LIBFT)
			@$(CC) $(BOBJS) -o $@ $(LDFLAGS)
			@echo "(BNAME) compiled successfully"

$(BOBJS_DIR)/%.o:	$(BSRCS_DIR)/%.c
			@mkdir -p $(BOBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $(BNAME)..."

$(LIBFT):
			@$(MAKE) all bonus -C $(LIBFT_DIR)

clean:
			@$(RM) $(OBJS_DIR)
			@$(RM) $(BOBJS_DIR)
			@$(MAKE) clean -C $(LIBFT_DIR)
			@echo "Cleaning obj files."

fclean:	
			@echo "Cleaning all files."
			@$(MAKE) clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(MAKE) fclean -C $(LIBFT_DIR)

re:
			@echo "Rebuild $(NAME)"
			@$(MAKE) fclean
			@$(MAKE) all

.PHONY: all clean fclean re bonus
.INTERMEDIATE:	$(OBJS) $(BOBJS)
# .SECONDARY: $(SRCS) $(OBJS)
