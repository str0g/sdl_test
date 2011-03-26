CPPFLAGS=-Wall -Werror -g 
include ../Makefile.shared
OBJSHPP=
OBJS=../out/src/main.o ../out/src/test_runner.o ../out/libsdltest.so
../out/test_runner:$(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $^ -o $@
clean:
	rm -r $(OBJS) ../out/test_runner 
.PHONY: clean test_runner
