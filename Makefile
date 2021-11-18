LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCFILES	= minishell.c \
			  ms_init_list.c \
			  ms_builtins.c \
			  ms_parser.c \
			  ms_prompt.c \
			  ms_utils.c \
			  ms_utils2.c \
			  ms_init_data.c \
			  ms_init_patterns.c \
			  ms_parser_patterns.c \
			  ms_builtin_echo.c \
			  ms_builtin_pwd.c \
			  ms_builtin_export.c \
			  ms_builtin_unset.c \
			  ms_builtin_env.c \
			  ms_builtin_cd.c \
			  ms_builtin_exit.c \
			  ms_translate.c \
			  ms_translate_trim.c \
			  ms_init_flags.c \
			  ms_parser_presplit.c \
			  ms_executer.c \
			  ms_reinit.c \
			  ms_executer_system.c \
			  ms_executer_utils.c \
			  ms_executer_builtin.c \

BONUSFILES	= bonus.c \


CC			= clang -g3
RM			= rm -f
CFLAGS		=
SRCDIR		= src
BONUSDIR	= srcbonus
OBJDIR		= obj
HEADER		= minishell.h
#BONUSHEADER= checker.h
NAME		= minishell
#BONUSNAME	= checker
INCLUDES	= -I./libft -I./
LINKS		= -I$(LIBFTPATH) -L$(LIBFTPATH) -lft -lreadline

SRC			= $(addprefix $(SRCDIR)/, $(SRCFILES))
#BONUSSRC	= $(addprefix $(BONUSDIR)/, $(BONUSFILES))
OBJ			= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
#BONUSOBJ	= $(BONUSSRC:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)

all:		mkdir $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			make -C $(LIBFTPATH) all
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS)

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
			valgrind --leak-check=full ./$(NAME)

.PHONY:		all clean fclean re
