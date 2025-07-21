#include <iostream>
#include <cstdlib>
#include "FunzioneBase.h"
#include "Bisezione.h"
#include "Tan.h"
#include <cmath>

using namespace std; 

int main (int argc, char** argv){

    if ( argc!= 4 ) {
        cerr << "Usage: " << argv[0] << " <Precisione> <nMin> <nMax>" << endl;
        exit(-1);
    }

    double prec = atof(argv[1]);
    unsigned int nMin = atof(argv[2]);
    unsigned int nMax = atof(argv[3]);

    if(nMin < 1){
        while(nMin < 1 ){
            cout<<"Il valore minimo di nMin consentito è 1, reinserisci un valore corretto"<<endl; 
            cin >> nMin; 
        }
    }

    Tan t; 
    Bisezione bisezione(prec, nMax, nMin);

    for (int i = nMin; i<=nMax; i++){
        double a  = i * M_PI; 
        double b = i * M_PI + (2*M_PI/2);

    }















}