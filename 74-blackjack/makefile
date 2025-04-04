# Set the C and C++ compilers
CC := gcc
CXX := g++

# Set the target executable
TARGET_EXEC := main

# Set the build and source directories
BUILD_DIR := ./build
SRC_DIR := ./src

# Find all the C and C++ files in the source directory
SRCS := $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c')

# Each C or C++ file should be compiled into an object file (.o) and a dependency file (.d)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Include each folder in the source directory in the list to be searched for header files
INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Flags to provide warnings and debugging information
DEBUG_FLAGS := -ggdb -pedantic-errors -Wall -Wextra -Wconversion -Wsign-conversion -Werror
CXX_DEBUG_FLAGS := -Weffc++
# The --MMD and -MP flags generate makefiles with header dependencies
DEPENDENCY_FLAGS := -MMD -MD

# Set the flags
CPPFLAGS := $(INC_FLAGS) $(DEBUG_FLAGS) $(DEPENDENCY_FLAGS)
CXXFLAGS := $(CXX_DEBUG_FLAGS)

# Final build step
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) 

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d dependency makefiles
# Suppress errors of missing makefiles using - at the front, as they will be missing initially
-include $(DEPS)
