# 43_libft_tester

Simple libft tester. Clone your libft in libft folder.

Remaining:

1. Finish all test functions
2. Create sh script to automatically make, run program, and run valgrind (only printing errors)

Extra:

1. Let user choose which tests to run (through command line?)
2. Explicitly tell user how they failed
3. Fix norm (?)
4. Fix ugly malloc protection (and some are missing notably in manual tests)
5. Fix random function which is the most basic one and only generates 0 to INT_MAX

Unsure how to test:
(so simple you can just read the code anyway)

- putchar_fd
- putstr_fd
- putnbr_fd
- putendl_fd

(only way I see to test is writing to a file and comparing with printf and diff - this uses pipex tech and I haven't done it yet)


Done:

- isascii
- isalnum
- isalpha
- isdigit
- isprint
- tolower
- toupper
- atoi
- strnstr
- bzero
- memset
- memchr
- strchr
- strrchr
- memcpy
- strlcpy
- strlen
- memcmp
- strncmp
- memmove
- strdup
- strlcat
- calloc

- itoa

Working on:


Remaining:

- split
- join
- striteri
- strmapi
- strtrim
- substr

- lstaddback
- lstaddfront
- lstsize
- lstmap
- lstiter
- lstdelone
- lstclear
- lstlast
- lstnew
