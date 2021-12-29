CC           = gcc
CFLAGS       = -c -Wall -g -Os
LD           = $(CC)
LDFLAGS      = -lstdc++
LDTESTFLAGS += $(LDFLAGS) -lgtest
SRC_TARGET   = matrix
TEST_TARGET  = matrix_test
SRC_OBJECTS  = $(patsubst %.cpp, %.o, $(shell find ./src -name "*.cpp"))
TEST_OBJECTS = $(patsubst %.cpp, %.o, src/matrix.cpp test/mat_test.cpp)

all: $(SRC_TARGET)

test: $(TEST_TARGET)

$(SRC_TARGET): $(SRC_OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(LD) -o $@ $^ $(LDTESTFLAGS)

# You don't even need to be explicit here,
# compiling C files is handled automagically by Make.
%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

# clean:
	# rm $(TARGET) $(OBJECTS)
