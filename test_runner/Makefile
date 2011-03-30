CPPFLAGS=-Wall -g -std=c++0x#-Werror 

OUTPUT_PATH=../out
TARGET_NAME = test_runner
TARGET := $(OUTPUT_PATH)/$(TARGET_NAME)
OUTPUT_PATH_SRC := $(OUTPUT_PATH)/_$(TARGET_NAME)/src

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=$(OUTPUT_PATH)/_$(TARGET_NAME)/%.o) $(OUTPUT_PATH)/libsdltest.so

include ../Makefile.shared

$(TARGET):$(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $^ -o $@
clean:
	rm -r $(OBJS) $(TARGET) 
.PHONY: clean $(TARGET_NAME)
