CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o Player.o Potion.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Potion.h Player.h

Player.o: Player.cpp Player.h Potion.h Random.h

Potion.o: Potion.cpp Potion.h

.PHONY: clean
clean:
	rm -f *.o main
