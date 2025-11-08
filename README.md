#43_libft_tester

Simple libft tester. Clone your libft in libft folder.

Will not work for partial libfts and might or might not work with/without bonus (to be done).
Ideally every test should be independent so incomplete libfts can still be tested.
No ETA on completion (gotta move on to funnier stuff).

###Todo or not todo:

0. Split all the tests so that I can test incomplete libft's (or if something does not compile)
1. Let user choose which tests to run (through command line?)
	1. Also give the option to run super extensive thorough tests for 1 func (big TEST_N)
2. Explicitly tell user how they failed
3. Figure out a way to test when a function over-allocates ?
4. Fix random function which is the most basic one and only generates 0 to INT_MAX
	1. Fixed at least to generate diff numbers with each exec (with time())

###Unsure how to test:
(so simple you can just read the code anyway)

- putchar_fd
- putstr_fd
- putnbr_fd
- putendl_fd

(only way I see to test is writing to a file and comparing with printf and diff - this uses pipex tech and I haven't done it yet)


###Done:

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
- join
- substr
- split
- strtrim
- striteri
- strmapi

###Working on:

- lstnew
- lstaddback
- lstaddfront
- lstsize
- lstmap
- lstiter
- lstdelone
- lstclear
- lstlast
