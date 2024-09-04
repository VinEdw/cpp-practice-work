CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects = main.o Point3d.o Vector3d.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp Point3d.h Vector3d.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Point3d.o: Point3d.cpp Point3d.h Vector3d.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Vector3d.o: Vector3d.cpp Vector3d.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
