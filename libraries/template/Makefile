NAME := {{LIB_NAME}}
LANG := c++

SRC_DIR := src
INC_DIR := include
BIN_DIR := bin
OBJ_DIR := obj

ifeq ($(LANG),c++)
	CC := g++
	SRC_EXT := cpp
else
	CC := gcc
	SRC_EXT := c
endif

SRCS := $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJS := $(patsubst $(SRC_DIR)/%.$(SRC_EXT),$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS := -I$(INC_DIR) -Wall -Wextra -O2

all: $(BIN_DIR)/lib$(NAME).a

$(BIN_DIR)/lib$(NAME).a: $(OBJS)
	@mkdir -p $(BIN_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
