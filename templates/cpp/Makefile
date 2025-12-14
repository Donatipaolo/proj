# Makefile per progetto C++

PROJECT_NAME := {{PROJECT_NAME}}

# Sorgente principale
SRC := src/main.cpp

# Cartella di output eseguibile
BIN := bin/$(PROJECT_NAME)

# Compiler e flags
CXX := g++
CXXFLAGS := -Wall -O2 -Iinclude

# Includi le librerie aggiunte tramite proj
-include libs.mk

# Aggiungi qui di default gli include delle librerie
CXXFLAGS += $(INCLUDE_DIRS)

# Librerie e linker flags
LDFLAGS := $(LIB_DIRS)
LDLIBS := $(LIBS)

all: $(BIN)

# Regola per compilare l’eseguibile
$(BIN): $(SRC)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf bin/*
