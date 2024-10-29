linux: raylib/raylib.h
	mkdir build
	g++ src/*.cpp -o build/leaf-project -Lraylib -lraylib -O3
	cp -r music build/

clean: build
	rm -r build
