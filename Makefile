CC      = gcc
AR      = ar
ARFLAGS = rcs

# =========================
# Compiler flags
# =========================

CFLAGS   = -Wall -Wextra -Werror -Wpedantic -std=c11 -Iinclude
CFLAGS  += -O2
LDFLAGS  = -L$(BUILD_DIR) -lft
TEST_INC = -Iinclude/core

# Debug build: make debug
debug: CFLAGS += -g -DLIBFT_DEBUG -fsanitize=address,undefined
debug: LDFLAGS += -fsanitize=address,undefined
debug: all

# =========================
# Directories
# =========================

BUILD_DIR = build
OBJ_DIR   = $(BUILD_DIR)/obj
TEST_DIR  = $(BUILD_DIR)/tests

# =========================
# Library
# =========================

LIB = $(BUILD_DIR)/libft.a

# All sources: one level deep inside src/ (src/*/*.c)
# Automatically includes: ctype, memory, stdio, stdlib, string,
#   unistd, ds, algo, internal — and any future module.
SRC = $(wildcard src/*/*.c)
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# =========================
# Tests
# =========================

# tests/*/*.c — covers both legacy (tests/string/*.c) and
# new module tests (tests/ds/*.c, tests/algo/*.c, etc.)
TESTS     = $(wildcard tests/*/*.c)

TEST_BINS = $(patsubst tests/%.c,$(TEST_DIR)/%,$(TESTS))

# =========================
# Main targets
# =========================

all: $(LIB) $(TEST_BINS)

# Run all tests
test: all
	@echo ""
	@echo "========================================"
	@echo "  Running test suite"
	@echo "========================================"
	@PASS=0; FAIL=0; \
	for bin in $(TEST_BINS); do \
		if [ -f $$bin ]; then \
			echo ""; \
			echo "--- $$bin ---"; \
			$$bin; \
			if [ $$? -eq 0 ]; then PASS=$$((PASS+1)); \
			else FAIL=$$((FAIL+1)); fi; \
		fi; \
	done; \
	echo ""; \
	echo "========================================"; \
	echo "  Suites: $$PASS passed, $$FAIL failed"; \
	echo "========================================"; \
	[ $$FAIL -eq 0 ]

# Run only DS tests
test_ds: all
	@for bin in $(TEST_DIR)/ds/*; do \
		if [ -f $$bin ]; then echo "--- $$bin ---"; $$bin; fi; \
	done



# =========================
# Object compilation
# =========================

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(LIB): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(AR) $(ARFLAGS) $@ $^
	@echo "Built: $@  ($(words $(OBJ)) objects)"



# =========================
# Test binary compilation
# =========================

$(TEST_DIR)/%: tests/%.c $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TEST_INC) -include libft.h $< $(LDFLAGS) -o $@

# =========================
# Cleanup
# =========================

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(LIB)

re: clean all

.PHONY: all clean re test test_ds debug

