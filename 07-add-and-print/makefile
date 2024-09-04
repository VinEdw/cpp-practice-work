CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror

main: main.o io.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp io.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

io.o: io.cpp io.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
