CPPFLAGS=-Wall -shared -fPIC -Wl,-export-dynamic -std=c++0x#-O2 -Werror
include ../Makefile.shared
LDFLAGS=
INC_SDL=-D_GNU_SOURCE=1 -D_REENTRANT -I/usr/include/SDL #$(pkg-config sdl --cflags)
LD_SDL=-lSDL -lSDL_image #$(pkg-config sdl --libs) -lSDL_image
OBJSHPP=
OBJS=../out/src/event_test.o ../out/src/alpha_blending.o ../out/src/inherit_templates.o ../out/src/smartSurface.o ../out/src/common_dev.o ../out/src/temp.o
../out/libsdltest.so:$(OBJS) $(OBJSHPP)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(INC_SDL) $(LD_SDL) $^ -o $@
clean:
	rm -r $(OBJS) $(OBJSHPP) ../out/libsdltest.so
.PHONY: clean libsdltest.so
