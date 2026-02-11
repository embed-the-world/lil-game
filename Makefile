
.PHONY: all build compile run clean

all: build compile run
	@echo "all done!"

build:
	@echo "***** building *****"
	mkdir -p build
	cmake -S src -B build

compile:
	@echo "***** compiling *****"
	cmake --build build

run:
	@echo "***** startin programm *****"
	build/bin/main

clean:
	rm -rf build/*
	@echo "***** cleaning sources *****"




