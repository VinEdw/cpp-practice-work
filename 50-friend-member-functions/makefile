CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o Point3d.o Vector3d.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Point3d.h Vector3d.h

Point3d.o: Point3d.cpp Point3d.h Vector3d.h

Vector3d.o: Vector3d.cpp Vector3d.h

.PHONY: clean
clean:
	rm -f *.o main
