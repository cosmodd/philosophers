# SOURCES
SRCS	= srcs/action.c \
		srcs/brain.c \
		srcs/checks.c \
		srcs/error.c \
		srcs/forks.c \
		srcs/free.c \
		srcs/init.c \
		srcs/main.c \
		srcs/time.c \

OBJS	= $(SRCS:.c=.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INCS	= -Iincludes

LIBS	=

C_OPTS	= $(CFLAGS) $(INCS)
BIN_OPT	= $(LIBS) $(INCS)

# OTHER
NAME	= philo
SHELL	= zsh
REDO	= \r\e[2K

# COLORS
BG_RD	= \033[48;2;237;66;69m
BG_GR	= \033[48;2;0;194;60m
BG_BL	= \033[48;2;88;101;242m
FG_WH	= \033[38;2;255;255;255m
FG_BK	= \033[38;2;0;0;0m
BOLD	= \033[1m
NOCOL	= \033[0m

# CHARS
TICK	= ✓
PEN		= ✐
CROSS	= 𐄂

# MESSAGES
VALID	= $(BOLD)$(FG_WH)$(BG_GR) $(TICK)
INFO	= $(BOLD)$(FG_WH)$(BG_BL) $(PEN)
DEL		= $(BOLD)$(FG_WH)$(BG_RD) $(CROSS)

.c.o:
	@$(CC) $(C_OPTS) -c $< -o $@
	@echo -n "$(REDO)$(INFO) $(notdir $@) $(NOCOL)"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(BIN_OPT) $^ -o $@
	@echo "$(REDO)$(VALID) $@ $(NOCOL)"

debug:
	@rm -f $(OBJS)
	@echo "$(DEL) $(words $(OBJS)) obj files $(NOCOL)"
	@rm -f $(NAME)
	@echo "$(DEL) $(NAME) binary $(NOCOL)"
	@make -s CFLAGS="$(CFLAGS) -g" BIN_OPT="$(BIN_OPT) -fsanitize=address"

valgrind:
	@rm -f $(OBJS)
	@echo "$(DEL) $(words $(OBJS)) obj files $(NOCOL)"
	@rm -f $(NAME)
	@echo "$(DEL) $(NAME) binary $(NOCOL)"
	@make -s CFLAGS="$(CFLAGS) -g"
	@valgrind --leak-check=full ./$(NAME)

clean:
	@rm -f $(OBJS)
	@echo "$(DEL) $(words $(OBJS)) obj files $(NOCOL)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(DEL) $(NAME) binary $(NOCOL)"

re: fclean all

run: all
	@./$(NAME)

run-debug: debug
	@./$(NAME)

.PHONY: all clean fclean re debug run run-debug valgrind
