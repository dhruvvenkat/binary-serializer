CXX ?= g++
AR ?= ar

BUILD_DIR := build
TARGET := binary-serializer
LIB := $(BUILD_DIR)/libbinary_serializer.a

CPPFLAGS += -Iinclude
CXXFLAGS += -std=c++20 -Wall -Wextra -Wpedantic -O2 -MMD -MP
LDFLAGS +=
LDLIBS +=

LIB_SRCS := $(filter-out src/main.cpp,$(wildcard src/*.cpp))
APP_SRCS := src/main.cpp

LIB_OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(LIB_SRCS))
APP_OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(APP_SRCS))
DEPS := $(LIB_OBJS:.o=.d) $(APP_OBJS:.o=.d)

.PHONY: all app run clean

all: $(LIB)

app: $(TARGET)

$(TARGET): $(APP_OBJS) $(LIB)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(LIB): $(LIB_OBJS)
	@mkdir -p $(@D)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) -r $(BUILD_DIR) $(TARGET)

-include $(DEPS)
