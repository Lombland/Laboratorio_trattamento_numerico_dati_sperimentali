#include "funzioni.h"

int main(int argc, char** argv){


    if (argc < 3){
    cout << "Uso del programma : "<<argv[0]<< "<n_data> <filename>"<<endl; 
    return 1;
    }
    cout<< (argv[1])<<endl; 
    cout <<"Qua 1"<<endl; 

    //Numero di dati contenuti nell'array

    int ndata = atoi(argv[1]);
     cout <<"Qua 2 "<<endl;
    //Creo un array dinamico di dimensio ndata

    //Do a filename il noe del file
    char* filename = argv[2]; 
    cout <<"Qua 3"<<endl;

    //Carico e stampo l'array 

    Vettore v = Read(ndata, filename);

    //Calcolo varianza e media 
    double media = calcolaMedia(v);
    double varianza = calcolaVarianza(v);

    Print(v, filename);

    cout<<"Media: "<<media<<", Varianza: "<<varianza<<endl; 

    Vettore w;
    w=v; 

    selectionSort(w);
    cout<<"Vettore ordinato:"<<endl;
    Print(w);

    double mediana = calcolaMediana(w);

    cout<<endl<<"Mediana: "<<mediana<<endl; 

    return 0;
}