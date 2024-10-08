CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp Random.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
