#ifndef __INTEGRALEMC_H__
#define __INTEGRALEMC_H__

#include "RandomGen.h"
#include "FunzioneBase.h"
#include <vector>
#include <cmath>

using namespace std; 

class IntegraleMC {

    public: 
    IntegraleMC(unsigned int seed):m_gen(seed){
        m_errore = 0;
        m_punti = 0;
    }

    virtual double Integra(const FunzioneBase& F,double inf, double sup, unsigned int punti, double fmax) = 0;

    double GetErrore() const {return m_errore;};
    unsigned int GetN() const {return m_punti;};

    protected : 
    RandomGen m_gen;
    double m_errore;
    unsigned int m_punti;

};

class IntegratoreMedia : public IntegraleMC {

    public:
    IntegratoreMedia (unsigned int seed) : IntegraleMC(seed){;}

    virtual double Integra(const FunzioneBase& F,double inf, double sup, unsigned int punti, double fmax) override{

        double somma {0.}; 
        double intervallo = sup-inf; 
        vector<double> x; 


        for(unsigned int i{0}; i<punti; i++){
            double appo = m_gen.Rand(); 
            x.push_back(appo);
            somma += F.Eval(appo); 
        }

        double media = somma/punti; 
        double risultato = media *intervallo; 
        double sum2 {0.};

        for(unsigned int i{0}; i<punti; i++){
            sum2 += pow(F.Eval(x[i])-media,2);
        }
        double sigmaf = sqrt(sum2/(punti-1));
        m_errore = (sigmaf*intervallo)/sqrt(punti);

        m_punti = punti;

        return risultato; 
    }

};

#endif
