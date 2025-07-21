#ifndef __Solutore_h__
#define __Solutore_h__

#include "FunzioneBase.h"
#include "Parabola.h"

class Solutore{

    public: 

    Solutore(){
        m_prec=0.001;
        m_nmax=1000; 
        m_ninterations=0; 
    };
    Solutore(double prec){
        m_prec=prec;
        m_nmax=1000; 
        m_ninterations=0; 
    };

    virtual ~Solutore() {};

    virtual double cercaZeriPointer(double xMin,
                                    double xMax,
                                    const FunzioneBase* f,
                                    double prec = 0.001,
                                    unsigned int nMax= 1000) =0 ;   
    virtual double cercaZeriReference(double xMin,
                                     double xMax,
                                     const FunzioneBase& f,
                                     double prec = 0.001,
                                     unsigned int nMax= 1000) =0 ; 
    virtual double cercaZeriPointerTan(double a,
                                       double b,
                                       const FunzioneBase* f,
                                       double prec,
                                       unsigned int nMax,
                                       unsigned int nMin )=0;
    virtual double cercaZeriReferenceTan(double xMin,
                                         double xMax,
                                         const FunzioneBase& f,
                                         double prec = 0.001,
                                         unsigned int nMax= 1000) =0 ;
                                    

    void SetPrecisione(double epsilon){m_prec = epsilon; };
    double GetPrecisione(){return m_prec;};   

    void SetMaxIteraction(unsigned int n){m_nmax = n;};
    unsigned int GetMaxIteraction(){return m_nmax;};

    unsigned int GetNIteraction() {return m_ninterations;};

    protected:
    double m_a, m_b; //Estremi intervalli ricerca 
    double m_prec; //Precisione richiesta 
    unsigned int m_nmax, m_nmin; //Massimo numero di interazioni permesse 
    unsigned int m_ninterations; //Numero di interazioni effetuate
};


#endif