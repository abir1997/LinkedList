.default: all

PROGRAMS=week06

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

week06: Node.o LinkedList.o main.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
