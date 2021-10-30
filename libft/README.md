# Libft - An implementation of the C Standard Library

This is the first project of the 42 Programming School.It is both an introduction to programming in C as well as a basis on which you will build the rest of the school's projects.

- - -

## What i learned?

This project gives an overview of many C programming concepts with a focus in string and memory manipulation, pointers and linked lists. All of which will be very helpful later on the course.

Aside from functions that make system calls everything that we create must be based on functions that we have coded ourselves. Thus this is the most important project in the syllabus and one that we will iterate on over time.

## My badge

![Libft badge](/docs/libftm.png)

## My grade

![Libft badge](/docs/libftgrade.png)

## How to use

`git clone https://github.com/VLN37/libft.git`

`make`

`clang main.c libft.a  -I ./inc && ./a.out`

you can also compile your libft with my main to use my unit tests

also possible to use these functions in your other C projects

#### Functions from `<ctype.h>`

* [`ft_isdigit`](/src/ft_isdigit.c) - Checks if a given character is numeric
* [`ft_isalpha`](/src/ft_isalpha.c) - Checks if a given character is alphabetic
* [`ft_isalnum`](/src/ft_isalnum.c) - Checks if a given character is alphanumeric
* [`ft_isprint`](/src/ft_isprint.c) - Checks if a given character is printable
* [`ft_isascii`](/src/ft_isascii.c) - Checks if a given character belongs in the ASCII table
* [`ft_tolower`](/src/ft_tolower.c) - If uppercase, returns its lowercase equivalent
* [`ft_toupper`](/src/ft_toupper.c) - If lowercase, returns its uppercase equivalent


#### Functions from `<string.h>`
* [`ft_memset`](/src/ft_memset.c) - overwites the next *n* bytes of data with the specified character
* [`ft_memcpy`](/src/ft_memcpy.c) - copies *n* bytes of data from source to destination
* [`ft_memmove`](/src/ft_memmove.c) - copies *n* bytes of data from source to destination, with treatment for possibly overlapping addresses
* [`ft_memchr`](/src/ft_memchr.c) - returns the first ocurrence of *c* in the first *n* bytes of memory
* [`ft_memcmp`](/src/ft_memcmp.c) - assess whether the first *n* bytes are equal
* [`ft_strncmp`](/src/ft_strcmp.c) - assess whether the first *n* characters of a string are equal
* [`ft_strchr`](/src/ft_strchr.c) - returns the first ocurrence of the character *c* in *str*
* [`ft_strrchr`](/src/ft_strrchr.c) - returns the last ocurrence of the character *c* in *str*
* [`ft_bzero`](/src/ft_bzero.c) - overwrites the next *n* bytes of data with zeros
* [`ft_strlen`](/src/ft_strlen.c) - Returns the size of the string passed as argument
* [`ft_strdup`](/src/ft_strdup.c) - Duplicates a string, returning a new address
* [`ft_strnstr`](/src/ft_strnstr.c) - finds the first ocurrence of a string within a string

#### Functions from `<stdlib.h>`

* [`ft_calloc`](/src/ft_calloc.c) - allocates *n* bytes of data and initializes them all with zeros*
* [`ft_atoi`](/src/ft_atoi.c) - Converts a string to an integer

#### Non-standard functions
* [`ft_substr`](/src/ft_substr.c) - Extract a portion of a string
* [`ft_strjoin`](/src/ft_strjoin.c) - Concatenates two strings returning a new one
* [`ft_strtrim`](/src/ft_strtrim.c) - removes a set of characters from the beggining and end of a string
* [`ft_split`](/src/ft_split.c) - Slices the string into several others delimited by the character *c*
* [`ft_itoa`](/src/ft_itoa.c) - Converts an integer into a string
* [`ft_strmapi`](/src/ft_strmapi.c) - Applies a function to every character of the string
* [`ft_striteri`](/src/ft_striteri.c) - Applies a function to every address of the string
* [`ft_putchar_fd`](/src/ft_strmapi.c) - Writes a character in the given file descriptor
* [`ft_putnbr_fd`](/src/ft_strmapi.c) - Writes a number in the given file descriptor
* [`ft_putstr_fd`](/src/ft_strmapi.c) - Writes a string in the given file descriptor
* [`ft_putendl_fd`](/src/ft_strmapi.c) - Writes a string in the given file descriptor, followed by a newline

#### Linked-list functions

* [`ft_lstnew`](/src/ft_lstnew.c) - creates a new struct node
* [`ft_lstsize`](/src/ft_lstsize.c) - Returns the size of the list
* [`ft_lstlast`](/src/ft_lstlast.c) - Returns the address of the last element in the list
* [`ft_lstadd_front`](/src/ft_lstadd_front.c) - adds a new node to the start of the list
* [`ft_lstadd_back`](/src/ft_lstadd_back.c) - adds a new node to the end of the list
* [`ft_lstclear`](/src/ft_lstclear.c) - frees the memory of all nodes and their respective contents
* [`ft_lstiter`](/src/ft_lstiter.c) - applies the function *f* to the contents of every node
* [`ft_lstmap`](/src/ft_lstmap.c) - copies the entire list and applies the function *f* to the contents of every node

## License

This project is licensed under the MIT terms, [available here](LICENSE)
