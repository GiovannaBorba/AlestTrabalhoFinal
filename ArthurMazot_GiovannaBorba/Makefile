CFLAGS=-c -std=c++11
EXEC=app
all: ${EXEC}

${EXEC}: main.o ArvoreBinariadeBusca.o Nodo.o
	@g++ main.o ArvoreBinariadeBusca.o Nodo.o -o ${EXEC}

main.o: main.cpp ArvoreBinariadeBusca.hpp Nodo.hpp
	@g++ ${CFLAGS} main.cpp

ArvoreBinariadeBusca.o: ArvoreBinariadeBusca.cpp ArvoreBinariadeBusca.hpp Nodo.hpp
	@g++ ${CFLAGS} ArvoreBinariadeBusca.cpp

Nodo.o: Nodo.cpp Nodo.hpp
	@g++ ${CFLAGS} Nodo.cpp

clear: 
	@rm -f *.o ${EXEC}

run: ${EXEC}
	@./${EXEC}