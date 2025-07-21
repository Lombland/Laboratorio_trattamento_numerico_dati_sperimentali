2.2 : 2.2.o Vettore.o funzioni.o
	g++ -o 2.2 2.2.o Vettore.o funzioni.o
funzioni.o: funzioni.cpp funzioni.h Vettore.h
    g++ -c -o funzioni.o funzioni.cpp
esercizio2.2.o : 2.2.cpp funzioni.h Vettore.h
    g++ -c -o 2.2.o 2.2.cpp
Vettore.o : Vettore.cpp Vettore.h
    g++ -c -o Vettore.o Vettore.cpp

clean:
    rm *.o
cleanall: clean
    rm 2.2
