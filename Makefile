LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	minishell.c \
					main.c \
					builtins/ms_builtin_echo.c \
					builtins/ms_builtin_pwd.c \
					builtins/ms_builtin_export.c \
					builtins/ms_builtin_unset.c \
					builtins/ms_builtin_env.c \
					builtins/ms_builtin_cd.c \
					builtins/ms_builtin_exit.c \
					execute/ms_execute.c \
					execute/ms_execute_system.c \
					execute/ms_execute_builtin.c \
					execute/ms_execute_dup_utils.c \
					execute/ms_execute_dup.c \
					init/ms_init_list.c \
					init/ms_init_data.c \
					init/ms_init_patterns.c \
					init/ms_init_flags.c \
					init/ms_reinit.c \
					parse/ms_parse.c \
					parse/ms_parse_patterns.c \
					parse/ms_parse_presplit.c \
					parse/ms_parse_flags.c \
					prompt/ms_prompt.c \
					prompt/ms_prompt_validate.c \
					prompt/ms_prompt_validate_files.c \
					prompt/ms_prompt_buf.c \
					prompt/ms_prompt_colors.c \
					prompt/ms_prompt_utils.c \
					signals/ms_signals.c \
					signals/ms_signals_utils.c \
					translate/ms_translate.c \
					translate/ms_translate_trim.c \
					translate/ms_translate_star.c \
					utils/ms_utils.c \
					utils/ms_utils_env.c \
					utils/ms_utils_print.c \
					utils/ms_error.c \

SOURCES_DIR		=	src
OBJ_DIR			=	obj
HEADER			=	minishell.h
SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME			=	minishell
CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3

INCLUDES		=	-I./libft -I./
LINKS			=	-lreadline -lcurses

VPATH			=	src src/builtins src/execute src/init src/parse \
					src/prompt src/signals src/translate src/utils \

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LINKS) -o $(NAME)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR):
					mkdir -p obj
					mkdir -p obj/builtins
					mkdir -p obj/execute
					mkdir -p obj/init
					mkdir -p obj/parse
					mkdir -p obj/prompt
					mkdir -p obj/translate
					mkdir -p obj/utils
					mkdir -p obj/signals

run:				all
					./$(NAME)

runv:				all
					valgrind --leak-check=full -s --trace-children=yes --error-exitcode=1 --track-origins=yes ./$(NAME)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft bonus
