CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11 -Iinclude

AR = ar
ARFLAGS = rcs

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = $(BUILD_DIR)/tests

LIB = $(BUILD_DIR)/libmini.a

# =========================
# Source files
# =========================

STRING_SRC = $(wildcard src/string/*.c)
MEMORY_SRC = $(wildcard src/memory/*.c)
IO_SRC = $(wildcard src/io/*.c)
CONV_SRC = $(wildcard src/conversion/*.c)

SRC = \
	$(STRING_SRC) \
	$(MEMORY_SRC) \
	$(IO_SRC) \
	$(CONV_SRC)

# =========================
# Object files
# =========================

OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# =========================
# Test files
# =========================

STRING_TESTS = $(wildcard tests/string/*.c)
MEMORY_TESTS = $(wildcard tests/memory/*.c)
IO_TESTS = $(wildcard tests/io/*.c)
CONV_TESTS = $(wildcard tests/conversion/*.c)

TESTS = \
	$(STRING_TESTS) \
	$(MEMORY_TESTS) \
	$(IO_TESTS) \
	$(CONV_TESTS)

TEST_BINS = $(patsubst tests/%.c,$(TEST_DIR)/%,$(TESTS))

# =========================
# Main targets
# =========================

all: $(LIB)

test: $(LIB) $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do \
		echo "Running $$test_bin"; \
		./$$test_bin; \
	done

# =========================
# Library
# =========================

$(LIB): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) $@ $^

# =========================
# Object compilation
# =========================

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================
# Test compilation
# =========================

$(TEST_DIR)/%: tests/%.c $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR) -lmini -o $@

# =========================
# Cleanup
# =========================

clean:
	rm -rf $(BUILD_DIR)
	find . -name "*.o" -delete

re: clean all

.PHONY: all clean re test
