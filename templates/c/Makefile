# Makefile per progetto C

PROJECT_NAME := {{PROJECT_NAME}}

# Sorgente principale
SRC := src/main.c

# Cartella di output eseguibile
BIN := bin/$(PROJECT_NAME)

# Compiler e flags
CC := gcc
CFLAGS := -Wall -O2 -Iinclude

# Includi le librerie aggiunte tramite proj
-include libs.mk

# Aggiungi include path delle librerie
CFLAGS += $(INCLUDE_DIRS)

# Librerie e linker flags
LDFLAGS := $(LIB_DIRS)
LDLIBS := $(LIBS)

all: $(BIN)

# Regola per compilare l’eseguibile
$(BIN): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf bin/*
