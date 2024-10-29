linux: raylib/raylib.h
	mkdir build
	g++ src/*.cpp -o build/leaf-project -Lraylib -lraylib -O3
	cp -r music build/

windows: raylib/raylib.h
	mkdir build
	x86_64-w64-mingw32-g++ src/*.cpp -o build/leaf-project -Lraylib -lraylibw -lgdi32 -lwinmm -O3 -static
	cp -r music build/


clean: build
	rm -r build
