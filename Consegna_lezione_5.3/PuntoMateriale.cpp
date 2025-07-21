#include "PuntoMateriale.h"

#include<iostream>
#include<cmath>
using namespace std; 


const double epsilon_0 = 8.854187817e-12; 
const double G = 6.67430e-11; 
PuntoMateriale :: PuntoMateriale(double massa, double carica, const Posizione&p): Posizione(p), Particella(massa, carica){ };
PuntoMateriale :: PuntoMateriale(double massa, double carica, double x, double y, double z): Posizione(x,y,z), Particella(massa, carica){ };

PuntoMateriale :: ~PuntoMateriale(){ }; 

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& p)const{

    double m_epsilon0 = 8.854E-12;

    double dx = p.getX()-getX();
    double dy = p.getY()-getY(); 
    double dz = p.getZ()-getZ();
    double r = sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));

    if (r == 0) {
        cerr << "Errore: il punto di osservazione coincide con il punto materiale." << std::endl;
        return CampoVettoriale(getX(), getY(), getZ(), 0, 0, 0);
    }

    double costante = GetCarica() / (4 * M_PI * m_epsilon0 * pow(r, 3));
    double Ex = costante * dx;
    double Ey = costante * dy;
    double Ez = costante * dz;

    return CampoVettoriale(p, Ex, Ey, Ez );

}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& p)const {
    double G = 6.6725E-11;

    double dx = p.getX()-getX();
    double dy = p.getY()-getY(); 
    double dz = p.getZ()-getZ();
    double r = sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));

    if (r == 0){
        cerr<<"Errore: la massa generatrice e massa graitazionale coincidono"<<endl;
        return CampoVettoriale(getX(), getY(), getZ(), 0, 0, 0);
    }

    double Gx = dx*G*(GetMassa())*(1/pow(r,3));
    double Gy = dy*G*(GetMassa())*(1/pow(r,3));
    double Gz = dz*G*(GetMassa())*(1/pow(r,3));

    return CampoVettoriale(p, Gx, Gy, Gz);

}