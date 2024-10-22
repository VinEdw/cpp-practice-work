CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o Card.o Deck.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Settings.h Card.h Deck.h

Card.o: Card.cpp Card.h

Deck.o: Deck.cpp Deck.h Card.h Random.h

.PHONY: clean
clean:
	rm -f *.o main
