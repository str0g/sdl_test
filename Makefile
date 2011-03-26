build:
	@echo "choose what would you like to compile"
all: libsdltest testrunner

testrunner:
	make -C test_runner
libsdltest:
	make -C libsdltest
clean: cleanlibsdltest cleantestrunner

cleanlibsdltest:
	make -C libsdltest clean
cleantestrunner:
	make -C test_runner clean
.PHONY: all testrunner libsdltest cleanlibsdltest cleantestrunner
