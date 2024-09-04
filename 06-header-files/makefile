CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror

main: main.o add.o input.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp add.h input.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

add.o: add.cpp add.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

input.o: input.cpp input.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
