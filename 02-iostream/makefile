debug_args := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror

all: iostream

iostream: iostream.cpp
	g++ $(debug_args) -o iostream iostream.cpp

clean:
	rm -f iostream
