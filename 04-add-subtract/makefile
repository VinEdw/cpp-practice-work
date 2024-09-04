debug_args := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror

all: add_subtract

add_subtract: add_subtract.cpp
	g++ $(debug_args) -o add_subtract add_subtract.cpp

clean:
	rm -f add_subtract
