CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects = main.o Point2d.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp Point2d.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Point2d.o: Point2d.cpp Point2d.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
