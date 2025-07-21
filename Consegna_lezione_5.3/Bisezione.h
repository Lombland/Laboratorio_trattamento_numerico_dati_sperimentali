#ifndef __Bisezione_h__
#define __Bisezione_h__ 

#include "Segno.h"
#include "Solutore.h"
#include <iostream>
#include "Parabola.h"

using namespace std; 

class Bisezione : public Solutore {

    public: 
    Bisezione(){
        m_prec=0.001;
        m_nmax=20; 
        m_nmin=1;
        m_ninterations=0; 
    };
    Bisezione(double prec, int nMax, int nMin){
        m_prec=prec;
        m_nmax=nMax; 
        m_nmin=nMin;
                m_ninterations=0;
    };
    virtual ~Bisezione(){};

   virtual double cercaZeriPointer(double xMin,
                                    double xMax,
                                    const FunzioneBase* f,
                                    double prec = 0.001,
                                    unsigned int nMax= 1000 ) override
    {
        
        if(f->Eval(xMax)*f->Eval(xMin) >=0){
            cerr<<"Funzione costante in 0, o sempre positiva"<<endl;
            exit(4);
        }

        double c = (xMin + xMax) / 2;

        for (unsigned int i=0; i<m_nmax; i++ ){

            c = (xMin + xMax) / 2;

            if(abs(f->Eval(c))<prec){
                cout<<"E' stato trovato uno zero nella funzione, x= "<<c<<endl;
                return c;
            }


            if(f->Eval(xMin)*f->Eval(c) < 0){
                xMax = c;
            }else{
                xMin = c;
            }


        }

        cout<<"La funzione no contiene zeri nell'intervallo: ["<<xMin<<","<<xMax<<"]"<<endl;             
        return c;    
    }

    virtual double cercaZeriReference(double xMin,
                                      double xMax,
                                      const FunzioneBase& f,
                                      double prec = 0.001,
                                      unsigned int nMax= 1000 ) override

    {
        
        if(f.Eval(xMax)*f.Eval(xMin) >=0){
            cerr<<"Funzione costante in 0, o sempre positiva"<<endl;
            exit(4);
        }

        double c = (xMin + xMax) / 2;

        for (unsigned int i=0; i<nMax; i++ ){

            c = (xMin + xMax) / 2;

            if(abs(f.Eval(c))<prec){
                cout<<"E' stato trovato uno zero nella funzione, x= "<<c<<endl;
                return c;
            }


            if(f.Eval(xMin)*f.Eval(c) < 0){
                xMax = c;
            }else{
                xMin = c;
            }


        }

        cout<<"La funzione non contiene zeri nell'intervallo: ["<<xMin<<","<<xMax<<"]"<<endl;   
        return c; 
    }
    
    virtual double cercaZeriPointerTan(double a,
                                       double b,
                                       const FunzioneBase* f,
                                       double prec,
                                       unsigned int nMax,
                                       unsigned int nMin  ) override
    {   
        double fa = f->Eval(a); 
        double fb = f->Eval(b);

        if (fa * fb >0){
            cerr << "Errore: l'intervallo non contiene una radice." << endl;
            return NAN;
        }        

        double c;
        while ((b-a)/2 >prec) {
            c = (a+b)/2;
            double fc = f->Eval(c);

            if (fc == 0) {
                return c; // Trovata la radice esatta
            } else if (fa*fc < 0) {
                b = c;
                fb = fc;
            } else {
                a = c;
                fa = fc;
            }
        }
    }
                    
};

#endif