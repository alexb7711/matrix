##===============================================================================
# Configuration

# Directories
BIN = bin
SRC = src
TST = test
OBJ = obj

# Virtual paths
vpath %.cpp $(SRC)
vpath %.cpp $(TST)

# Compiler
CC     = gcc
CFLAGS = -c -Wall -g -Os

# Linking
LD           = $(CC)
LDFLAGS      = -lstdc++
LDTESTFLAGS += $(LDFLAGS) -lgtest

# Source files
SRC_TARGET    = $(BIN)/matrix
SRC_FILES     = $(shell find ./src -name "*.cpp")
SRC_OBJECTS  := $(patsubst %.cpp, $(OBJ)/%.o, $(notdir $(SRC_FILES)))

# Test files
TEST_TARGET   = $(BIN)/matrix_test
TEST_FILES    = $(shell find . ! -name "main.cpp" -name "*.cpp")
TEST_OBJECTS := $(patsubst %.cpp, $(OBJ)/%.o, $(notdir $(TEST_FILES)))

##===============================================================================
# Recipes

##-------------------------------------------------------------------------------
# Class

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
all: $(BIN) $(OBJ) $(SRC_TARGET)

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
$(SRC_TARGET): $(SRC_OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

##-------------------------------------------------------------------------------
# Test

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
test: $(BIN) $(OBJ) $(TEST_TARGET)

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
$(TEST_TARGET): $(TEST_OBJECTS)
	$(LD) -o $@ $^ $(LDTESTFLAGS)

##-------------------------------------------------------------------------------
# Global

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
$(OBJ)/%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
$(OBJ):
	@mkdir -p $(OBJ)

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
$(BIN):
	@mkdir -p $(BIN)

##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
clean:
	@rm -fv $(SRC_TARGET)
	@rm -fv $(TEST_TARGET)
	@rm -fv $(SRC_OBJECTS)
