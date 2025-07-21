#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <cmath>

class RandomGen{

    public: 

    RandomGen(unsigned int seed){
        m_seed = seed; 
        m_a = 1664525;
        m_c = 1013904223;
        m_m = 1LL << 31;
    };

    void SetA(unsigned int a){m_a=a;};
    void SetC(unsigned int c){m_c=c;};
    void SetM(unsigned int m){m_m=m;};

    double Rand(){
        m_seed = (m_seed*m_a+m_c)%m_m;
        return double(m_seed)/m_m;  
    };
    double Unif(double xmin, double xmax){
        return xmin+(xmax-xmin) * Rand();
    };
    double Exp(double lambda){
        return (-(log(1-Rand())/lambda));
    };
    double Gaus(double mean, double sigma){
        double s=Rand(); 
        double t=Rand();
        double x=sqrt(-2. * log(1.-s)) * cos(2. * M_PI * t);
        return mean+x*sigma; 
    };
    double GausAR(double mean, double sigma, double max){
        double x,y;
        do{
            x = Unif(mean -3 *sigma, mean + 3 * sigma);
            y = Unif(0, max);
        }while
            (y > (1 / (sqrt(2 * M_PI) * sigma)) * exp(-0.5 * pow((x - mean) / sigma, 2)));
        return x;
    };

    private: 
    unsigned int m_a, m_c, m_m;
    unsigned int m_seed; 
}; 



#endif