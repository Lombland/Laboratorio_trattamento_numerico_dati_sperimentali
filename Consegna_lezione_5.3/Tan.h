#ifndef __Tan_h__
#define __Tan_h__

#include "FunzioneBase.h"
#include <cmath>

class Tan : public FunzioneBase {
   
    public: 

    Tan(){
    m_prec = 0.000001;
    m_nMin = 1; 
    m_nMax = 20;
    };

    Tan(double prec){
    m_prec =prec;
    };
    
    ~Tan(){};

    virtual double Eval(double x) const override{
        return sin(x)-(x*cos(x));
    }

    void SetPrec(double epsilon){m_prec = epsilon;};
    double GetPrecisione(){return m_prec;};

    private: 
    double m_prec;
    double m_nMin, m_nMax;
};

#endif 