#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

class FunzioneBase{
    public: 
    virtual double Eval(double x) const =0;
    virtual ~FunzioneBase(){};
};

#endif