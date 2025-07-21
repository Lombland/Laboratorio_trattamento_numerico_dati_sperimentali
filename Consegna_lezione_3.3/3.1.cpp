#include <iostream>
#include <cstdlib>

#include <vector>

#include "funzioni.h"

using namespace std;

int main( int argc , char** argv ) {

    if ( argc < 3 ) {
        cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
        return -1 ;
    } 

    vector<double> v = Read<double>( atoi(argv[1]) , argv[2]); 

    cout<<endl<<"Stampo vettore "<<argv[2]<<endl;
    Print(v);

    cout<<endl<<"Media= "<<calcola_media<double>(v)<<endl;
    cout<<"Vatianza= "<<calcola_varianza<double>(v)<<endl;
    cout<<"Mediana= "<<calcola_mediana<double>(v)<<endl;
    
    return 0; 
}