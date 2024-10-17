CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o Point2d.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Point2d.h

Point2d.o: Point2d.cpp Point2d.h

.PHONY: clean
clean:
	rm -f *.o main
