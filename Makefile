NAME := pipex

D_LIBFT := ./libft/
LIBFT := $(D_LIBFT)/libft.a

D_SRC := ./
D_OBJ := ./obj
D_INC := ./

SRC := main.c
SRC += parse.c
SRC += cmd.c
SRC += exec.c

OBJ := $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
INC := -I$(D_INC)
INC += -I$(D_LIBFT)/include

LIB := -L$(D_LIBFT)
LIB += -lft

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

ifeq ($(DEBUG), 1)
CFLAGS += -g -fsanitize=address
endif

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LIB)

$(LIBFT):
	$(MAKE) -C $(D_LIBFT)

$(OBJ): | $(D_OBJ)

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(D_SRC)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(D_OBJ)
	$(MAKE) -C $(D_LIBFT) clean

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(D_LIBFT) fclean

.PHONY: re
re: fclean all

.PHONY: test
test:
	$(MAKE) re DEBUG=1
	./$(NAME) a.txt "ls -al" "wc -l" b.txt
