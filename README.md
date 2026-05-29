*This project has been created as part of the 42 curriculum by lbalderr.*

# Libft

## Description
The **Libft** project is a foundational milestone in the 42 curriculum. Its primary goal is to re-code a comprehensive selection of standard C library functions (`libc`), along with specialized utility functions to manipulate strings, memory and linked lists. 

In the C programming language standard functions are highly optimized and readily available. However, by writing these functions from scratch, this project forces a deep, hands-on understanding of memory allocation, pointer arithmetic, data structure design, and the low-level behavior of computer memory. The resulting static library (`libft.a`) serves as a highly efficient, reliable, and reusable toolkit that will be used extensively in almost all subsequent 42 C-based programming projects (such as *ft_printf* and *push_swap*).

## Instructions

### Prerequisites
To compile and use this library, you need a Unix-like environment (Linux or macOS) equipped with `make` and a standard C compiler like `gcc` or `cc`.

### Compilation Targets
The library includes a strict, 42-compliant Makefile supporting the standard compilation targets:

* `make` or `make all`: Compiles all core C functions and additional/linked list functions and generates the static library archive `libft.a`.
* `make clean`: Safely purges all object files (`.o`) from the directory.
* `make fclean`: Executes `clean` and completely deletes the compiled static library archive (`libft.a`).
* `make re`: Performs a full rebuild from scratch by running `fclean` followed by `all`.

### Integrating Libft into Your Projects
To use this library in an external C project:
1. Include the header file in your C source files:
	```c
	#include "libft.h"
	```
2. Compile your project files alongside libft.a:
	```Bash
	cc -Wall -Wextra -Werror main.c libft.a -o my_program
	```

## Detailed Library Description
The library contains a wide variety of utilities categorized by their structural behaviors. Every function is engineered to handle extreme bounds, edge cases and NULL-pointer defenses safely.

### 1. Libc Functions (Standard Replacements)
These functions precisely replicate the behavior of standard functions found within `<ctype.h>`, `<string.h>` and `<stdlib.h>`.

* Memory Management:

   * ft_memset: Fills a byte string with a byte value.

   * ft_bzero: Erases the data in a given memory block by writing zeros (\0) to it.

   * ft_memcpy: Copies a memory area from a source block to a destination block.

   * ft_memmove: Copies a memory area safely, guaranteeing protection against overlapping memory blocks.

   * ft_memchr: Locates a specific byte character within a targeted byte sequence.

   * ft_memcmp: Compares two distinct memory blocks byte-by-byte.

   * ft_calloc: Dynamically allocates memory for an array, initializes all its bytes to zero, and protects against integer overflows via internal __SIZE_MAX__ safety checks.

* String Classification & Inspection:

   * ft_isalpha / ft_isdigit / ft_isalnum / ft_isascii / ft_isprint: Tests a character for alphabetical, numerical, alphanumeric, ASCII compliance or printable qualities, respectively.

   * ft_strlen: Calculates the exact length of a string (excluding the null terminator).

   * ft_toupper / ft_tolower: Converts a character case to uppercase or lowercase.

* String Manipulation & Searching:

   * ft_strchr / ft_strrchr: Locates the first or last occurrence of a character in a string, respectively.

   * ft_strncmp: Compares two strings up to a specified number of characters.

   * ft_strlcpy: Copies a string to a size-bounded buffer with guaranteed null-termination.

   * ft_strlcat: Concatenates two strings within a size-bounded buffer with guaranteed null-termination.

   * ft_strnstr: Locates a substring within a size-bounded string sequence.

   * ft_strdup: Duplicates a string by allocating matching memory space dynamically on the heap.

   * ft_atoi: Converts a string representation of an integer into an actual int value, handling white spaces and signs.

### 2. Additional Utility Functions
These functions are not part of the standard C library but provide essential mechanics for string slicing, mutations and writing to a specific file descriptor.

* ft_substr: Extracts a substring from a string starting at a specified index with a maximum length limit.

* ft_strjoin: Concatenates two individual strings together into a brand new heap-allocated string block.

* ft_strtrim: Trims all specified characters from the absolute beginning and end of a string.

* ft_split: Splits a string into an array of strings using a single specified delimiter character.

* ft_itoa: Converts a signed integer value into a null-terminated string representation (handling negative numbers smoothly).

* ft_strmapi: Applies a function to each character of a string to create a new modified string.

* ft_striteri: Iterates over each character of a string by reference, applying a modification function directly in place.

* ft_putchar_fd / ft_putstr_fd / ft_putendl_fd / ft_putnbr_fd: Outputs a character, string, newline-terminated string or integer, respectively, directly to a specified file descriptor (fd), allowing seamless redirection to stdout, stderr or text files.

### 3. Linked List Engine
The third part implements a dynamically allocated singly linked list structure to manage data arrays flexibly. The nodes use the following struct:

```C
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}	t_list;
```
* ft_lstnew: Allocates and initializes a new list node structure with its content.

* ft_lstadd_front: Prepends a new node to the absolute front of a linked list.

* ft_lstsize: Counts the exact number of nodes currently inside a linked list.

* ft_lstlast: Progresses through a list to return a tracking pointer to the absolute last non-null node.

* ft_lstadd_back: Appends a node safely to the trailing back of a linked list.

* ft_lstdelone: Cleanses a targeted node's content using a custom del function pointer and frees the node memory without triggering a cascade delete.

* ft_lstclear: Iterates through an entire linked list, deleting and freeing all nodes and clearing out the original head reference to prevent dangling references.

* ft_lstiter: Traverses a list to execute a function across all node contents.

* ft_lstmap: Iterates through a list, transforms each node's data through a function pointer and creates a completely separate, new linked list while maintaining robust rollback safety guards if any allocation fails midway.

## Resources and References

* C Programming - A Modern Approach (Second Edition), K. N. King.

* [GeeksforGeeks](https://www.geeksforgeeks.org/): Has articles explaining the use of functions, data types and concepts/algorithms in simple language.

* Linux Programmer's Manual (man pages): Accessible in terminal scopes via `man 3 function_name`

## Use of Artificial Intelligence (AI)

In alignment with modern software documentation standards, an AI assistant was utilized as an engineering peer throughout the development of this library. Below is a detailed breakdown of the tasks and sections where AI was applied:

1. Code Review & Structural Refactoring:

   * AI assisted in validating functions like ft_lstlast, ft_lstadd_back and ft_lstclear to ensure strict Norminette compliance, efficient pointer management and clean tracking states.

   * Assisted in rebuilding functions like ft_lstmap to incorporate missing explicit rollback structure (del + ft_lstclear), making sure that a memory allocation failure midway through building a new list does not trigger memory leaks.

2. Edge-Case Troubleshooting:

   * AI was used to analyze third-party unit test suite outputs (specifically Tripouille's libftTester). It successfully debugged an erratic LEAKS.KO message on test 5 of ft_calloc by clarifying how negative integer underflows (INT_MIN) cast into an unsigned size_t behave on 64-bit platforms, confirming it as an artifact of the tester's macro structure rather than an actual memory leak.

3. Makefile Architecture Optimization:

   * Assisted in organizing the Makefile layout, ensuring correct archive creation using ar rc and ranlib without relying on potentially dangerous wildcards (like ft_*.c).

4. README structure and contents
   * AI was used to generate the general structure of this README file and the detailed description section, summarizing the contents of the project. All generated outputs were carefully read and edited by the author to ensure they accurately describe and fit the requirements of the project.