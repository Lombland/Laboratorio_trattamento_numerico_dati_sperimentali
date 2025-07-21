#include "CampoVettoriale.h"
#include <iostream>
#include <cmath> 

using namespace std; 

CampoVettoriale::CampoVettoriale(const Posizione& p): Posizione(p), m_Fx(0), m_Fy(0), m_Fz(0){ };

CampoVettoriale::CampoVettoriale(const Posizione& p, double Fx, double Fy, double Fz): Posizione(p), m_Fx(Fx), m_Fy(Fy), m_Fz(Fz){ };

CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz): Posizione(x,y,z), m_Fx(Fx), m_Fy(Fy), m_Fz(Fz) { };

double CampoVettoriale:: Modulo() const{
    return sqrt(pow(GetFx(),2)+pow(GetFy(),2)+pow(GetFz(),2));
}

CampoVettoriale& CampoVettoriale::operator+=(const CampoVettoriale& CV){
    m_Fx += CV.GetFx();
    m_Fy += CV.GetFy();
    m_Fz += CV.GetFz();

    return *this;
}

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale& CV)const{
    return CampoVettoriale(getX(), getY(), getZ(),
                           m_Fx + CV.GetFx(),
                           m_Fy + CV.GetFy(),
                           m_Fz + CV.GetFz());
}


