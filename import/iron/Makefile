CXX=c++
#CXXFLAGS=-std=c++98 -fno-elide-constructors
CXXFLAGS=-g -std=c++98 -I/usr/X11R6/include
LFLAGS=-L/usr/X11R6/lib -lGL

all:
	mkdir -p include
	cat src/iron/head.h > include/iron
	cat src/iron/panic.h >> include/iron
	cat src/iron/Value.h >> include/iron
	cat src/iron/Box.h >> include/iron
	cat src/iron/Ref.h >> include/iron
	cat src/iron/EnableRef.h >> include/iron
	cat src/iron/Vector.h >> include/iron
	cat src/iron/Array.h >> include/iron
	cat src/iron/String.h >> include/iron
	cat src/iron/File.h >> include/iron
	cat src/iron/tail.h >> include/iron

	$(CXX) $(CXXFLAGS) -otest -Iinclude src/test/*.cpp

clean:
	rm -rf include
	rm -f test
