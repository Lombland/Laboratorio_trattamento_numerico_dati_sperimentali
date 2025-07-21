#ifndef __EquazioniDifferenziali_h__ 
#define __EquazioniDifferenziali_h__ 

#include "VectorOperation.h"
#include <cmath>

using namespace std; 

class FunzioneVettorialeBase {

    public: 
    virtual vector<double> Eval(double t, const vector<double> & k)const = 0; 

};

class OscillatoreArmonico: public FunzioneVettorialeBase {
   
    public: 
    OscillatoreArmonico(double omega0) {m_omega0 = omega0;};

    virtual vector<double> Eval(double t, const vector<double> & k)const override{

        vector <double> derivate(2) ; 
        derivate[0] = k[1];
        derivate[1] = -(pow(m_omega0,2))*k[0]; 
        return derivate; 
    }

    private: 
    double m_omega0;
};

class EquazioneDifferenzialeBase {
    public:
    virtual vector<double> Passo(double t,
                                 const vector<double>& x,
                                 double h,
                                 const FunzioneVettorialeBase& f)const =0;
};

class Eulero : public EquazioneDifferenzialeBase{
    public:
    virtual vector<double> Passo(double t,
                                 const vector<double>& x,
                                 double h,
                                 const FunzioneVettorialeBase& f)const override{
        return x+(f.Eval(t, x))*h;
    }
                                
};

class RougeKutta :public EquazioneDifferenzialeBase{
    public: 
        virtual vector<double> Passo(double t,
                                 const vector<double>& x,
                                 double h,
                                 const FunzioneVettorialeBase& f)const override{
        
        vector<double> k1 = f.Eval(t, x);
        vector<double> k2 = f.Eval(t + h / 2, x + (k1 * (h / 2)));
        vector<double> k3 = f.Eval(t + h / 2, x + (k2 * (h / 2)));
        vector<double> k4 = f.Eval(t + h, x + (k3 * h));

        double due = 2; 
        return x + ((k1 + (due*k2) + (due*k3) + k4) * (h / 6));
        
    }
};

class Pendolo : public FunzioneVettorialeBase{
    public: 

        Pendolo(double omega0) {m_omega0 = omega0;};

        virtual vector<double> Eval(double t, const vector<double> & k)const override{
        
        vector<double> derivate(2); 
        derivate[0] = k[1]; 
        derivate[1] = m_omega0*sin(k[0]);
        
        return derivate; 
        }

        private: 
        double m_omega0;

    };

    class OscillatoreForzato : public FunzioneVettorialeBase{

        public: 

        OscillatoreForzato(double omega0, double omega, double alpha){
            m_omega0 = omega0; 
            m_alpha = alpha; 
            m_omega = omega;

        }

        virtual vector<double> Eval(double t, const vector<double> & k)const override{
        
            vector<double> derivate(2);

            derivate[0]=k[1];
            derivate[1]= -(pow(m_omega0,2)*k[0])-(m_alpha*derivate[0])+sin(m_omega*t);
            return derivate; 
            
        }



        private: 
        double m_omega0;
        double m_alpha; 
        double m_omega; 

    };


#endif