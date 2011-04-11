CPPFLAGS=-Wall -shared -fPIC -Wl,-export-dynamic -g #-std=c++0x-O2 -Werror

OUTPUT_PATH := ../out
TARGET_NAME = libsdltest.so
TARGET := $(OUTPUT_PATH)/$(TARGET_NAME)
OUTPUT_PATH_SRC := $(OUTPUT_PATH)/_$(TARGET_NAME)/src

LDFLAGS=
INC_SDL = $(shell pkg-config sdl --cflags)
LD_SDL = $(shell pkg-config sdl --libs) -lSDL_image
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=$(OUTPUT_PATH)/_$(TARGET_NAME)/%.o)

include ../Makefile.shared

$(TARGET):$(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(INC_SDL) $(LD_SDL) $^ -o $@
clean:
	rm -r $(OBJS) $(OBJSHPP) $(TARGET)
.PHONY: clean $(TARGET_NAME)
