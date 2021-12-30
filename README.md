# Minishell
The objective of this project is for you to create a simple [shell](https://en.wikipedia.org/wiki/Shell_(computing)). Yes, your little [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html) or [zsh](https://zsh.sourceforge.io/Doc/).

### What is Minishell?
Minishell is an individual project at [42](42sp.org.br) that requires us to create a simple [shell](https://en.wikipedia.org/wiki/Shell_(computing)). Minishell will introduce you to the world of shells, which provide a convenient text interface to interact with your system. Shells might seem very easy to understand but have very specific and defined behaviour in almost every single case, most of which will need to be handled properly.
Minishell runs executables from an absolute, relative or environment [PATH](https://en.wikipedia.org/wiki/PATH_(variable)) (/usr/bin/ls or ls), including arguments or options. ``'`` and ``"`` work the same as bash, except for multiline commands. Finally, you can use ``Ctrl-C`` to interrupt and ``Ctrl-\`` to quit a program, as well as ``Ctrl-D`` to throw an ``EOF``, same as in bash.
A few of the functions are ["built-in"](https://whimsical.com/minishell-R7ozXMj4gLMiR1nmeYoxDY@VsSo8s35VFfYzEkkZTzB7Q), meaning we don't call the executable, we re-coded them directly. It's the case for ``echo``, ``pwd``, ``cd``, ``env``, ``export``, ``unset`` and ``exit``. As part of the bonus, the operators ``&&``, ``||`` and the wildcard ``*`` are supported and behave like bash.

### Application flow
Click [here](https://whimsical.com/minishell-R7ozXMj4gLMiR1nmeYoxDY@VsSo8s35VGGzFQLEo2WUD6) for the interactive link.

### Demo
<img src="./images/demo2.gif" width="100%"/>

### Badge
<img src="./images/minishellm.png" width="150" height="150"/>

#### Objectives
- Unix logic

#### Skills
- Imperative programming
- Rigor
- Unix

#### Our grade
<img src="./images/score2.png" width="150" height="150"/>

## Getting started
**Follow the steps below**
```bash
# Requirements: GNU Readline Library
# To install the readline library, open the terminal window and write
sudo apt-get install libreadline-dev

# Clone the project and access the folder
git clone --recurse-submodules https://github.com/VLN37/Minishell.git && cd Minishell/

# Run make so you can build the program
make

# Run the program
./minishell

# Write any shell command like
echo "hello minishell"

# Quit the program
exit

# Clean output objects with
make fclean

# Well done!
```

## Updating

The project is regularly updated with bug fixes and code optimization.

## 📝 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](license) file for details.

---

Made by:
João Rodriguez 👋 [See my Github](https://github.com/VLN37)
Welton Leite 👋 [See my linkedin](https://www.linkedin.com/in/welton-leite-b3492985/)
