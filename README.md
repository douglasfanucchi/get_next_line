*This project has been created as part of the 42 curriculum by dode-lim.*

# Get Next Line

## Description

This is a function, written in C language, to read lines from a file descriptor.

Given a file descriptor that references a text file, socket, standard input, pipe etc., it reads one line and return it in a freeable memory. In further calls, it will return the line right next to the previous one.

In case of `EOF` or invalid file descriptor, the function returns `NULL`.

It identifies the end of a line by the character `\n`. All returned lines has the `\n` character at the end of the string, except the last line if the file does not end with a `\n`.

For binary files it has undefined behavior.

Both time and space complexity of the function are `O(n)` where `n` stands for the length of the line.

## Instructions

To use this function you need to compile the `get_next_line.c` and `get_next_line_utils.c` files among the objects (or executable) of your project.

It is also necessary to include the header `get_next_line.h` in those `.c` files you want to use the function.

**IMPORTANT:** Since the string returned is allocated with `malloc`, you should use `free` on it to avoid memory leaks.

### Example:
Given the following directory structure:

    .
    ├── get_next_line.c
    ├── get_next_line.h
	├── get_next_line_utils.c
    ├── hello.txt
    └── main.c

Where `hello.txt` has `hello world\n` in it.

The following `main.c`

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("hello.txt", O_RDONLY);

	char *line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%p", line);

	free(line);
	close(fd);
}
```

will print `hello world\n` and `NIL` on the terminal, since `get_next_line` returns the line on the first call and returns `NULL` on the second one.


To compile and execute the example, you should run `cc get_next_line.c get_next_line_utils.c main.c` and execute by running `./a.out`.

## Resources
  - <a href="https://www.geeksforgeeks.org/cpp/how-to-compile-and-run-a-c-c-code-in-linux/" target="_blank">How to compile and execute C programs in Linux</a>
  - <a href="https://man7.org/linux/man-pages/man2/open.2.html">Open function manual</a>
  - <a href="https://man7.org/linux/man-pages/man2/close.2.html">Close function manual</a>
  - <a href="https://man7.org/linux/man-pages/man3/malloc.3.html">Malloc function manual</a>
  - <a href="https://man7.org/linux/man-pages/man1/free.1.html">Free function manual</a>
- <a href="https://medium.com/@tharinduimalka915/linux-file-descriptors-ec945fd36893">File Descriptors</a>

AI was not used in this project.