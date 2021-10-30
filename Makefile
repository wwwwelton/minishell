LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

SRCFILES	= file.c \


BONUSFILES	= bonus.c \


CC			= clang
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= src
BONUSDIR	= srcbonus
OBJDIR		= obj
HEADER		= minishell.h
#BONUSHEADER	= checker.h
NAME		= minishell
#BONUSNAME	= checker
INCLUDES	= -I./libft -I./
LINKS		= -I $(LIBFTPATH) -L $(LIBFTPATH) -lft

SRC		= $(addprefix $(SRCDIR)/, $(SRCFILES))
#BONUSSRC= $(addprefix $(BONUSDIR)/, $(BONUSFILES))
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

.PHONY:		all clean fclean re
