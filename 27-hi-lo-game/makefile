CXXFLAGS := -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
objects := main.o extraction.o prompts.o

main: $(objects)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(objects): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Random.h prompts.h

extraction.o: extraction.cpp

prompts.o: prompts.cpp prompts.h extraction.h 

.PHONY: clean
clean:
	rm -f *.o main
