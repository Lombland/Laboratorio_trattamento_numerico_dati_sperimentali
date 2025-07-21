#include "funzioni.h"

Vettore Read(int nData, const char* filename){

    Vettore V(nData);
    ifstream in(filename);
    for(unsigned int i=0; i<nData; i++){
        in >> V[i];
    }
    in.close(); 
    return V;
}

double calcolaMedia(const Vettore& V){
    double sum = 0; 
    for(unsigned int i=0; i<V.getN(); i++){
        sum +=  V.getComponent(i);
    }
    return (sum/double(V.getN()));
}

double calcolaMediana(Vettore V){
    double md=0;
    if(V.getN() %2 == 0){
        md = (V[V.getN()/2]+V[(V.getN()/2)+1])/2; 
    }else{
        md = V[(V.getN()+1)/2];
    }
    return md;
}

double calcolaVarianza(const Vettore& V){
    double med = calcolaVarianza(V);
    double scartoquadro = 0;
    for(unsigned int i=0; i<V.getN(); i++){
        scartoquadro += (V.getComponent(i)-med)*(V.getComponent(i)-med);
    }
    return (scartoquadro/V.getN());
}


void Print (const Vettore& V){
    for(unsigned int i = 0; i<V.getN(); i++){
        cout << V.getComponent(i)<<" ";
    }
    cout<<endl; 
}

void Print( const Vettore & V , const char* filename ){
    cout<<"Gli elementi del file: "<<filename<<", sono "<<endl;
    Print(V); 
}

void selectionSort( Vettore& V){
    for(unsigned int i=0; i<V.getN()-1; i++){
        for(unsigned int j=i+1; j<V.getN(); j++){
            if(V[i]>V[j]){
                V.scambia(V[j],V[i]);
            }
        }
    }
}