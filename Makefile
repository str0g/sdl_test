build:
	@echo "choose what would you like to compile"
all: libsdltest testrunner

testrunner:
	make -C test_runner
libsdltest:
	make -C libsdltest

installDependenciesForUbuntu:
	@sudo apt-get update
	@sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev
	
clean:
	rm -r out
cleanlibsdltest:
	make -C libsdltest clean
cleantestrunner:
	make -C test_runner clean
.PHONY: all testrunner libsdltest cleanlibsdltest cleantestrunner
