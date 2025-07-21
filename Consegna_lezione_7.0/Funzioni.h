#ifndef __Funzioni_h__
#define __Funzioni_h__ 

#include "FunzioneBase.h"
#include "cmath"

class Funzioni : public FunzioneBase {

    public:
    virtual double Eval(double x) const override {
        return x*sin(x); 
    }

};

#endif 
