CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11

SRC = src/string/strlen.c \
      src/string/memcpy.c

OBJ = $(SRC:.c=.o)

LIB = build/libmini.a

TEST = build/test

all: $(LIB)

$(LIB): $(OBJ)
	mkdir -p build
	ar rcs $(LIB) $(OBJ)

$(TEST): $(LIB) tests/test.c
	$(CC) $(CFLAGS) tests/test.c -Lbuild -lmini -Iinclude -o $(TEST)

test: $(TEST)
	./$(TEST)

clean:
	rm -rf build
	find . -name "*.o" -delete

re: clean all
