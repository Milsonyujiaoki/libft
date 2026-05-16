*This project has been created as part of the 42 curriculum by Milsonyujiaoki.*

# libft

## Description

libft is an educational C library that reimplements common libc behavior and extends it with modular utilities for data structures, memory helpers, and algorithms.

Project goals:

- understand low-level API design in C;
- practice memory-safe manual allocation patterns;
- build and expose a reusable static library;
- exercise test-driven validation for core primitives.

Detailed overview of the library:

- `core`: fixed-width types, status codes, configuration macros, compiler helpers.
- `ctype`: character classification and case conversion (`ft_is*`, `ft_to*`).
- `string`: string operations and helpers (copy, compare, search, split, trim, tokenization).
- `memory`: raw memory operations and allocators (`mem*`, arena, pool, buffer).
- `stdlib-ft`: conversion utilities (`ft_atoi`, `ft_atol`, `ft_itoa`, etc.).
- `io/stdio`: output/input helpers and formatted output wrappers.
- `sys/unistd`: wrappers for basic POSIX calls (`read`, `write`, `close`).
- `ds`: custom containers (`t_slist`, `t_dlist`, `t_vector`, `t_stack`, `t_queue`).
- `42 bonus linked list`: canonical 42 list API with `t_list` node and `ft_lst*` functions.
- `algo`: sorting, searching, hashing, and comparison helpers.

Linked list requirement (42 bonus) implemented:

- `t_list` is declared in `include/libft.h` as:
  - `void *content`
  - `struct s_list *next`
- Implemented functions:
  - `ft_lstnew`
  - `ft_lstadd_front`
  - `ft_lstsize`
  - `ft_lstlast`
  - `ft_lstadd_back`
  - `ft_lstdelone`
  - `ft_lstclear`
  - `ft_lstiter`
  - `ft_lstmap`

Current project snapshot:

- static library output: `build/libft.a`
- source files: 82 (`src/*/*.c`)
- test files: 51 (`tests/*/*.c`)
- main public entrypoint: `include/libft.h`

## Instructions

Compilation and execution:

```bash
# Build library and all tests
make all

# Run full test suite
make test

# Run data-structure tests only
make test_ds

# Debug build with sanitizers
make debug

# Clean artifacts
make clean

# Rebuild from scratch
make re
```

Using the library in your code:

```c
#include "libft.h"

int main(void)
{
    const char *msg = "Hello, mini_libc";
    ft_printf("%s (%zu)\n", msg, ft_strlen(msg));
    return (0);
}
```

Link command example:

```bash
gcc -Iinclude your_file.c -Lbuild -lft
```

Notes:

- target architecture: x86_64
- naming convention: `ft_` prefix for symbol isolation
- project includes compatibility wrappers for legacy DS include paths under `include/ds/linkedList/`

## Resources

Classic references for libc and low-level C:

- The Linux Programming Interface, Michael Kerrisk
- Advanced Programming in the UNIX Environment, W. Richard Stevens
- C11 standard drafts and committee papers (ISO/IEC 9899)
- Linux man-pages project: `man 3 malloc`, `man 3 strlen`, `man 2 write`, etc.
- GNU C Library manual (glibc)
- cppreference C documentation: https://en.cppreference.com/w/c

How AI was used in this project:

- AI assisted in refactoring module headers and include-path organization.
- AI assisted in drafting and restructuring this README according to 42 requirements.
- AI was used as an implementation and review accelerator; all changes were compiled and tested locally afterward.

## License

Educational use only.
