NAME = libft.a

D_SRC = src
D_OBJ = obj
D_INC = include

SRC = $(addsuffix .c, \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlen \
	ft_strlcpy \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_strncmp \
	ft_nbrlen \
	ft_atoi \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstsize \
	ft_lstlast \
	ft_lstiter \
	ft_lstmap \
	ft_is_set \
	ft_utoa \
	ft_putstr \
	ft_free_strs \
	ft_strreduce \
	)
SRC += $(addsuffix .c, \
	get_next_line/get_next_line \
	get_next_line/ft_strndup \
	)
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
INC = -I$(D_INC)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I$(D_INC)
RM = rm -f
#
# FORMAT
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
LF = \r\033[K
CRLF = \n$(LF)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

$(D_OBJ)/%.o: $(D_SRC)/%.c
	@mkdir -p $(D_OBJ)/$(shell echo $(dir $<) | sed 's/$(D_SRC)\///')
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -r $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
