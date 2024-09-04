# Use -ggdb when debugging
# Use -pedantic-errors to disable compiler extensions
# Use -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion to turn warning levels up to the maximum
# Use -Werror to treat warnings as errors, forcing you to fix them
debug_args := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
# Use -O2 -DNDEBUG for release builds
release_args := -O2 -DNDEBUG

all: HelloWorld

HelloWorld: HelloWorld.cpp
	g++ $(debug_args) -o HelloWorld HelloWorld.cpp
	# g++ $(release_args) -o HelloWorld HelloWorld.cpp

clean:
	rm -f HelloWorld
