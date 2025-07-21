#ifndef __Segno_h__
#define __Segno_h__ 

#include"FunzioneBase.h"

class Segno: public FunzioneBase{
    public:
    double Eval (double x) const {return (x==0.?0.:(x>0.?1.:-1));};
};

#endif