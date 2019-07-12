.default: all

PROGRAMS=week07

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

week07: Node.o DELinkedList.o main.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
