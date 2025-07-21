#include "Particella.h"
#include <iostream> 

using namespace std; 

Particella :: Particella(){
    
    m_massa = 0; 
    m_carica = 0; 

}

Particella::Particella(double massa, double carica){
    m_massa = massa; 
    m_carica = carica; 
}

Particella::~Particella(){

}

double Particella::GetMassa() const{
    return m_massa; 
}

double Particella::GetCarica() const{
    return m_carica;
}

void Particella::Print() const{
    cout<<"Particella: massa=  "<<m_massa<<" q= "<<m_carica<<endl; 
}
