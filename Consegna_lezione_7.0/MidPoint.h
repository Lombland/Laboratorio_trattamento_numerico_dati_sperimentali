#ifndef __MidPoint_h__
#define __MidPoint_h__ 

#include "Integral.h"
#include "FunzioneBase.h"
#include <iostream>

using namespace std; 

class MidPoint :  public Integral {

    public: 

    MidPoint(double a, double b) : Integral(a, b) {};  

    virtual double Integra(unsigned int nstep, const FunzioneBase& f) override {
        
        if (nstep <= 0) {
            cout<<"Errorre, numero di passi negativo o nullo"<<endl; 
            exit(-1);
        }

        m_nstep = nstep; 
        m_h = (m_b-m_a)/m_nstep; 

        m_sum = 0; 
        for(unsigned int i=0; i<m_nstep; i++){
            m_sum += f.Eval(m_a + (i+0.5)*m_h);
        }
        m_integral = m_sign*m_sum*m_h; 
        return m_integral; 
    }
    
    double Integra(double Prec, const FunzioneBase& f, unsigned int& Passi) override {
        if (Prec <= 0) {
            cout << "Errore: la precisione deve essere positiva" << endl;
            exit(-1);
        }

        Passi = 1;
        double Integral_N = Integra(Passi, f);
        double Integral_2N = Integra(Passi * 2, f);

        double errore = (4.0 / 3.0) * abs(Integral_2N - Integral_N);

        while (errore > Prec) {
            Passi *= 2; 
            Integral_N = Integral_2N;
            Integral_2N = Integra(Passi * 2, f);
            errore = (4.0 / 3.0) * abs(Integral_2N - Integral_N);  
        }

        return Integral_2N;
    }

};

#endif