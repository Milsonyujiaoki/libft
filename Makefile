# =========================================================
# Compiler / Archiver
# =========================================================

CC       = gcc
AR       = ar
ARFLAGS  = rcs

# =========================================================
# Project
# =========================================================

NAME     = libft

# =========================================================
# Directories
# =========================================================

SRC_DIR      = src
TEST_SRC_DIR = tests
INC_DIR      = include

BUILD_DIR    = build

STATIC_DIR   = $(BUILD_DIR)/static
SHARED_DIR   = $(BUILD_DIR)/shared

OBJ_DIR      = $(BUILD_DIR)/obj
OBJ_STATIC   = $(OBJ_DIR)/static
OBJ_SHARED   = $(OBJ_DIR)/shared

TEST_DIR     = $(BUILD_DIR)/tests

# =========================================================
# Library output
# =========================================================

STATIC_LIB   = $(STATIC_DIR)/$(NAME).a
SHARED_LIB   = $(SHARED_DIR)/$(NAME).so

# =========================================================
# Compiler flags
# =========================================================

CFLAGS       = -Wall -Wextra -Werror
CFLAGS      += -Wpedantic -std=c11
CFLAGS      += -O2
CFLAGS      += -I$(INC_DIR)
CFLAGS      += -MMD -MP

PIC_FLAGS    = -fPIC

LDFLAGS      = -L$(STATIC_DIR) -lft

TEST_INC     = -I$(INC_DIR)/core

# =========================================================
# Debug
# =========================================================

DEBUG_FLAGS  = -g3
DEBUG_FLAGS += -DLIBFT_DEBUG
DEBUG_FLAGS += -fsanitize=address,undefined

debug: CFLAGS += $(DEBUG_FLAGS)
debug: LDFLAGS += -fsanitize=address,undefined
debug: all

# =========================================================
# Sources
# =========================================================

SRC          = $(wildcard $(SRC_DIR)/*/*.c)

OBJ_STATICS  = $(patsubst $(SRC_DIR)/%.c,$(OBJ_STATIC)/%.o,$(SRC))
OBJ_SHAREDS  = $(patsubst $(SRC_DIR)/%.c,$(OBJ_SHARED)/%.o,$(SRC))

DEP_STATICS  = $(OBJ_STATICS:.o=.d)
DEP_SHAREDS  = $(OBJ_SHAREDS:.o=.d)

# =========================================================
# Tests
# =========================================================

TESTS        = $(wildcard $(TEST_SRC_DIR)/*/*.c)

TEST_BINS    = $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TESTS))

# =========================================================
# Main targets
# =========================================================

all: static tests

static: $(STATIC_LIB)

shared: $(SHARED_LIB)

tests: $(TEST_BINS)

# =========================================================
# Static objects
# =========================================================

$(OBJ_STATIC)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# =========================================================
# Shared objects (PIC)
# =========================================================

$(OBJ_SHARED)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(PIC_FLAGS) -c $< -o $@

# =========================================================
# Static library
# =========================================================

$(STATIC_LIB): $(OBJ_STATICS)
	@mkdir -p $(STATIC_DIR)
	$(AR) $(ARFLAGS) $@ $^
	@echo "Built static library: $@"

# =========================================================
# Shared library
# =========================================================

$(SHARED_LIB): $(OBJ_SHAREDS)
	@mkdir -p $(SHARED_DIR)
	$(CC) -shared -o $@ $^
	@echo "Built shared library: $@"

# =========================================================
# Test binaries
# =========================================================

$(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c $(STATIC_LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TEST_INC) \
		-include libft.h \
		$< $(LDFLAGS) -o $@

# =========================================================
# Run tests
# =========================================================

test: all
	@echo ""
	@echo "========================================"
	@echo " Running test suite"
	@echo "========================================"

	@PASS=0; FAIL=0; \
	for bin in $(TEST_BINS); do \
		if [ -f $$bin ]; then \
			echo ""; \
			echo "--- $$bin ---"; \
			$$bin; \
			if [ $$? -eq 0 ]; then \
				PASS=$$((PASS+1)); \
			else \
				FAIL=$$((FAIL+1)); \
			fi; \
		fi; \
	done; \
	echo ""; \
	echo "========================================"; \
	echo " Suites: $$PASS passed, $$FAIL failed"; \
	echo "========================================"; \
	[ $$FAIL -eq 0 ]

# =========================================================
# DS tests only
# =========================================================

test_ds: all
	@for bin in $(TEST_DIR)/ds/*; do \
		if [ -f $$bin ]; then \
			echo "--- $$bin ---"; \
			$$bin; \
		fi; \
	done

# =========================================================
# Install / Uninstall
# =========================================================

PREFIX ?= /usr/local

install: static shared
	@mkdir -p $(PREFIX)/include
	@mkdir -p $(PREFIX)/lib

	cp $(INC_DIR)/libft.h $(PREFIX)/include/
	cp $(STATIC_LIB) $(PREFIX)/lib/
	cp $(SHARED_LIB) $(PREFIX)/lib/

	@echo "Installed libft to $(PREFIX)"

uninstall:
	rm -f $(PREFIX)/include/libft.h
	rm -f $(PREFIX)/lib/libft.a
	rm -f $(PREFIX)/lib/libft.so

	@echo "Removed libft from $(PREFIX)"

# =========================================================
# Cleanup
# =========================================================

clean:
	rm -rf $(BUILD_DIR)

fclean: clean

re: fclean all

# =========================================================
# Dependency files
# =========================================================

-include $(DEP_STATICS)
-include $(DEP_SHAREDS)

# =========================================================
# Phony
# =========================================================

.PHONY: \
	all \
	static \
	shared \
	tests \
	test \
	test_ds \
	debug \
	install \
	uninstall \
	clean \
	fclean \
	re