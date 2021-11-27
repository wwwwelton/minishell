LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCFILES	= minishell.c \
			  ms_init_list.c \
			  ms_init_data.c \
			  ms_init_patterns.c \
			  ms_init_flags.c \
			  ms_builtins.c \
			  ms_prompt.c \
			  ms_prompt_validate.c \
			  ms_prompt_buf.c \
			  ms_parse.c \
			  ms_parse_patterns.c \
			  ms_parse_presplit.c \
			  ms_parse_flags.c \
			  ms_utils.c \
			  ms_utils_env.c \
			  ms_utils_print.c \
			  ms_builtin_echo.c \
			  ms_builtin_pwd.c \
			  ms_builtin_export.c \
			  ms_builtin_unset.c \
			  ms_builtin_env.c \
			  ms_builtin_cd.c \
			  ms_builtin_exit.c \
			  ms_translate.c \
			  ms_translate_trim.c \
			  ms_translate_star.c \
			  ms_execute.c \
			  ms_execute_system.c \
			  ms_execute_builtin.c \
			  ms_reinit.c \
			  ms_error.c \
			  ms_execute_dup_utils.c \
			  ms_execute_dup.c \
			  ms_signals.c \
			  ms_signals_utils.c \

BONUSFILES	= bonus.c \


CC			= clang -g3
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= src
BONUSDIR	= srcbonus
OBJDIR		= obj
HEADER		= minishell.h
#BONUSHEADER= checker.h
NAME		= minishell
#BONUSNAME	= checker
INCLUDES	= -I./libft -I./
LINKS		= -I$(LIBFTPATH) -L$(LIBFTPATH) -lft -lreadline -lcurses

SRC			= $(addprefix $(SRCDIR)/, $(SRCFILES))
#BONUSSRC	= $(addprefix $(BONUSDIR)/, $(BONUSFILES))
OBJ			= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
#BONUSOBJ	= $(BONUSSRC:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)

all:		mkdir $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			make -C $(LIBFTPATH) all
			$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME) $(LINKS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			$(RM) $(OBJ)
			rm -rf obj
			make -C $(LIBFTPATH) clean

fclean:		clean
			make -C $(LIBFTPATH) fclean
			$(RM) $(NAME)

mkdir:
			mkdir -p obj

re:			fclean all

run:		mkdir $(OBJ) $(HEADER)
			make -C libft
			$(CC) main.c $(OBJ) -o $(NAME) $(INCLUDES) $(LINKS)
			./$(NAME)

runv:		mkdir $(OBJ) $(HEADER)
			make -C libft
			$(CC) main.c $(OBJ) -o $(NAME) $(INCLUDES) $(LINKS)
			valgrind -q --leak-check=full ./$(NAME)

.PHONY:		all clean fclean re
