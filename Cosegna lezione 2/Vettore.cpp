#include "Vettore.h"

//costruttore senza argomenti 
Vettore::Vettore(){
    m_N = 0;
    m_v = NULL;
}

//costruttore con dimensione
Vettore::Vettore(int N){
    if( N <0 ){
        cout<<"Errore: Dinemnsione del vettore negativa"<<endl;
        exit(4);
    } else {
        m_N = N ; 
        m_v = new double[N];
        for(int k=0; k<m_N; k++) {
            m_v[k] = 0; 
        } 
    }
};

//copy constructor
Vettore::Vettore(const Vettore& V) {
    m_N = V.getN();
    m_v = new double[m_N];
    for (int i=0; i<m_N; i++) m_v[i]=V.getComponent(i);
}


//distruttore 
Vettore::~Vettore(){
    delete[] m_v;
    cout<<endl<<"Il distruttore è stato invocato"<<endl;
};

//metodi di accesso 
void Vettore :: setComponenet(int i, double a){
    if( i<m_N ){
        m_v[i] = a;
    }else{
        cout<<"Errore indice: "<<i<<", dimensione "<<m_N<<endl; 
        exit(1);
    }
};

//metodi interni 
double Vettore::getComponent(int i)const{
    if( i<m_N ){
        return m_v[i];
    }else
    {
        cout<<"Errore indice: "<<i<<", dimensione "<<m_N<<endl; 
        exit(2);

    }
};

Vettore& Vettore:: operator = (const Vettore& V){
    m_N = V.getN();
    if (m_v) delete[] m_v;
    m_v =  new double [m_N];
    for(int i=0; i<m_N; i++){
        m_v[i] = V.getComponent(i);
    }
    return *this;
};

double& Vettore :: operator[](int i){

    if( i<m_N ){
        return m_v[i];
    }else{
        cout<<"Errore indice: "<<i<<", dimensione "<<m_N<<endl; 
        exit(3);
    }

};

//metodi interni 
void Vettore ::scambia(int a, int b){
    double Vtemp = getComponent(a);
    setComponenet(a,getComponent(b));
    setComponenet(b, Vtemp);
}


