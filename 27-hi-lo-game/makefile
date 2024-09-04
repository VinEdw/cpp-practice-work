CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o extraction.o prompts.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp Random.h prompts.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

extraction.o: extraction.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

prompts.o: prompts.cpp prompts.h extraction.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o main
