#include <iostream> 
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Vettore.h"

using namespace std;

Vettore Read(int, const char*);

double calcolaMedia(const Vettore&);
double calcolaVarianza(const Vettore&); 
double calcolaMediana(Vettore);

void Print( const Vettore & ) ;
void Print( const Vettore & , const char* ) ;

void selectionSort( Vettore& );
