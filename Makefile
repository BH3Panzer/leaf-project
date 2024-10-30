linux: raylib/raylib.h
	mkdir build
	g++ -Wall -Wextra src/*.cpp -o build/leaf-project -Lraylib -lraylib -O3
	cp -r music build/

windows: raylib/raylib.h
	mkdir build
	x86_64-w64-mingw32-g++ -Wall -Wextra src/*.cpp -o build/leaf-project -Lraylib -lraylibw -lgdi32 -lwinmm -O3 -static
	cp -r music build/

web: raylib/raylib.h
	mkdir build
	em++ -Wall -Wextra src/*.cpp -o build/leaf-project.html -Lraylib -lraylibweb -O3 -s USE_GLFW=3 -s ASYNCIFY --shell-file raylib/minshell.html --preload-file music -DPLATFORM_WEB

clean: build
	rm -r build
