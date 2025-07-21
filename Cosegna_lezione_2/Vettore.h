
#include <iostream>

using namespace std; 

class Vettore{ 
    public : 

    //costruttori 
    Vettore(); //void constructor 
    Vettore(int N); //constructor 
    Vettore(const Vettore& ); //copy constructor 


    //distruttore 
    ~Vettore(); 

    //metodi 
    int getN()const{return m_N;};
    void setComponenet(int, double);
    double getComponent(int) const;
    Vettore& operator = (const Vettore&);
    double& operator[](int);

    void scambia(int, int);
    
    private: 
    int m_N; 
    double* m_v; 

};
