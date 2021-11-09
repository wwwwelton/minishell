LINKS = -L../libft -I../libft -lft

readline:
		make -C ../libft all
		clang readline.c -lreadline $(LINKS)
		valgrind ./a.out

getenv:
		make -C ../libft all
		clang getenv.c -lreadline $(LINKS)
		valgrind ./a.out

splitargs:
		make -C ../libft all
		clang splitargs.c -lreadline $(LINKS)
		valgrind ./a.out

chdir:
		make -C ../libft all
		clang chdir.c -lreadline $(LINKS)
		valgrind ./a.out

opendir:
		make -C ../libft all
		clang opendir.c -lreadline $(LINKS)
		./a.out

add_history:
		make -C ../libft all
		clang add_history.c -lreadline $(LINKS)
		valgrind ./a.out

envp:
		make -C ../libft all
		clang envp.c -lreadline $(LINKS)
		valgrind ./a.out

environ:
		make -C ../libft all
		clang environ.c -lreadline $(LINKS)
		./a.out
