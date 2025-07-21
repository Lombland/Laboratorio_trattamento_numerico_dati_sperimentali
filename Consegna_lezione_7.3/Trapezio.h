#ifndef __Trapezio_h__ 
#define __Trapezio_h__ 

#include "Integral.h"
#include "FunzioneBase.h"
#include <iostream>

using namespace std; 

class Trapezio : public Integral {

    public: 

    Trapezio(double a, double b) : Integral(a, b) {};  

    double Integra(unsigned int nstep, const FunzioneBase& f) override {
        m_nstep = nstep;
        m_h = (m_b - m_a) / m_nstep;
        m_sum = 0;
        double estremi = 0.5;

        for (unsigned int i = 0; i <= m_nstep; i++) {
            double x = m_a + i * m_h;
            m_sum += f.Eval(x) * ((i == 0 || i == m_nstep) ? estremi : 1.0);
        }

        return m_sum * m_h;
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