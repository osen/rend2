CXX=c++
#CXXFLAGS=-std=c++98 -fno-elide-constructors
CXXFLAGS=-std=c++98 -I/usr/X11R6/include
LFLAGS=-L/usr/X11R6/lib -lGL

all:
	mkdir -p include
	cat src/safe/head.h > include/safe
	cat src/safe/panic.h >> include/safe
	cat src/safe/Value.h >> include/safe
	cat src/safe/Box.h >> include/safe
	cat src/safe/Reference.h >> include/safe
	cat src/safe/Vector.h >> include/safe
	cat src/safe/File.h >> include/safe
	cat src/safe/tail.h >> include/safe

	$(CXX) $(CXXFLAGS) -otest -Iinclude src/test/*.cpp

clean:
	rm -rf include
	rm -f test
