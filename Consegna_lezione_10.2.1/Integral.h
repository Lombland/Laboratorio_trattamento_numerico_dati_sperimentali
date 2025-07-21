#ifndef __Integral_h__ 
#define __Integral_h__

#include "Funzioni.h"

#include <algorithm>

class Integral {

    public: 

    Integral(double a, double b){
    checkInterval(a,b); 
    m_nstep = 0; 
    m_h = 0; 
    m_sum = 0; 
    m_integral = 0; 
    }
    virtual double Integra(unsigned int nstep, const FunzioneBase& ) = 0; 


    protected: 

    void checkInterval(double a, double b ){
        m_a =  std::min(a,b); 
        m_b =  std::max(a,b); 
        if( a>b ){
            m_sign = -1; 
        }else{
             m_sign = 1;
        } 
    }
    
    unsigned int m_nstep; 
    double m_a, m_b; 
    double m_sum, m_integral, m_h;
    int m_sign; 

};

#endif 

