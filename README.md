# mini_libc

Educational reimplementation of a C standard library.

## Goals

- Understand libc internals
- Learn low-level systems programming
- Explore memory management
- Implement runtime primitives
- Study ABI and ELF behavior

## Project Structure

```
mini_libc/
├── include/              # Public headers (POSIX-compliant)
│   ├── ctype.h          # Character classification/manipulation (15 functions)
│   ├── string.h         # String and memory operations (21 functions)
│   ├── errno.h          # Error codes and errno variable
│   ├── stdio.h.backup   # Standard I/O (backup - uses system header)
│   ├── stdlib.h.backup  # General utilities (backup - uses system header)
│   └── unistd.h.backup  # POSIX API (backup - uses system header)
│
├── src/                 # Implementation organized by header
│   ├── ctype/          # Character functions (15 implemented)
│   ├── string/         # String functions (14 implemented)
│   ├── memory/         # Memory functions (7 total: 1 impl + 6 stubs)
│   ├── stdlib/         # Standard library (8 stubs)
│   ├── stdio/          # Standard I/O (5 stubs)
│   └── unistd/         # POSIX functions (3 stubs)
│
├── tests/              # Unit tests
│   ├── ctype/         # 13 tests for character functions
│   ├── string/        # 13 tests for string functions
│   └── memory/        # 1 test for memory functions
│
└── build/             # Compiled artifacts
    ├── libft.a        # Static library
    ├── obj/           # Object files
    └── tests/         # Compiled test binaries
```

## Implemented Modules

### ctype.h (15/15 functions implemented)
**Character Classification:**
- `ft_isdigit`, `ft_isxdigit`, `ft_islower`, `ft_isupper`
- `ft_isascii`, `ft_isalpha`, `ft_isalnum`
- `ft_isprint`, `ft_isspace`, `ft_isblank`
- `ft_isgraph`, `ft_iscntrl`, `ft_ispunct`

**Character Manipulation:**
- `ft_toupper`, `ft_tolower`

### string.h (14/14 string + 1/7 memory functions implemented)
**String Examination:**
- `ft_strlen`, `ft_strcmp`, `ft_strncmp`
- `ft_strchr`, `ft_strrchr`, `ft_strstr`, `ft_strtok`

**String Manipulation:**
- `ft_strcpy`, `ft_strncpy`, `ft_strcat`, `ft_strncat`
- `ft_strdup`, `ft_strndup` (stubs - require malloc)

**Memory Operations:**
- `ft_memcpy` ✅ (implemented)
- `ft_memset`, `ft_memccpy`, `ft_memmove`, `ft_memcmp`, `ft_memchr`, `ft_bzero` (stubs)

### stdlib.h, stdio.h, unistd.h (stubs created)
Function skeletons created for future implementation:
- **stdlib:** `ft_atoi`, `ft_atol`, `ft_malloc`, `ft_calloc`, `ft_free`, `ft_exit`, `ft_abort`, `ft_getenv`
- **stdio:** `ft_printf`, `ft_sprintf`, `ft_puts`, `ft_putchar`, `ft_getchar`
- **unistd:** `ft_write`, `ft_read`, `ft_close`

## Build Instructions

```bash
# Build library and tests
make all

# Run all tests
make test

# Clean build artifacts
make clean

# Rebuild from scratch
make re
```

## Usage

```c
#include <ctype.h>
#include <string.h>

int main(void) {
    char str[] = "Hello, World!";
    
    // Character classification
    if (ft_isalpha(str[0])) {
        str[0] = ft_tolower(str[0]);
    }
    
    // String operations
    size_t len = ft_strlen(str);
    char *dup = ft_strdup(str);  // Note: stub, returns NULL
    
    return 0;
}
```

Link with: `gcc -Iinclude your_file.c -Lbuild -lft`

## Architecture

- **x86_64** primary target
- Position-independent code
- No external dependencies (except system headers for testing)
- Prefix `ft_` to avoid symbol conflicts

## Testing

27 unit tests covering implemented functions:
- 13 ctype tests
- 13 string tests  
- 1 memory test

Run tests: `make test`

## License

Educational use only.
