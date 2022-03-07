# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC				=	c++
RM				=	rm -rf

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME			=	$1

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS			=	-Wall -Wextra -Werror
FSAN			=	-fsanitize=address
DEBUG			=	-g3 -O0

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR		=	srcs
INCS_DIR		=	incs

SRCS			=	($1).cpp \

INCS			=	($1).h \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS			=	$(addprefix $(SRCS_DIR)/,$(SRCS:.cpp=.o))

%.o				:	%.c
					$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)			:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(MLX_FLAGS)

all				:	$(NAME)

clean			:
					$(RM) $(OBJS) $(LIBFT_A)
					make clean -C $(LIBFT_DIR)

fclean			:	clean
					$(RM) $(NAME)
					make fclean -C $(LIBFT_DIR)

re				:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY			:	all bonus clean fclean re
