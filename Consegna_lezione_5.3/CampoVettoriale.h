#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__
#include "Posizione.h"

class CampoVettoriale : public Posizione{

    public:
    CampoVettoriale(const Posizione&);
    CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
    CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);

    CampoVettoriale & operator+= (const CampoVettoriale& );
    CampoVettoriale operator+(const CampoVettoriale& )const; 

    double GetFx() const {return m_Fx;};
    double GetFy() const {return m_Fy;}; 
    double GetFz() const {return m_Fz;}; 

    void SetFx(double Fx) {m_Fx = Fx;};
    void SetFy(double Fy) {m_Fy = Fy;};
    void SetFz(double Fz) {m_Fz = Fz;};

    double Modulo() const;
    
    private: 
    double m_Fx, m_Fy, m_Fz; 

};



#endif