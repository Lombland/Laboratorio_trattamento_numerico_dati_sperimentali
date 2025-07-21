#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include"Particella.h"
#include"Posizione.h"

#include"CampoVettoriale.h"

class PuntoMateriale: public Particella, public Posizione {
    
    public: 

        PuntoMateriale(double massa, double carica, const Posizione&);
        PuntoMateriale(double massa, double carica, double x, double y, double z);

        ~PuntoMateriale();

        CampoVettoriale CampoElettrico(const Posizione& ) const; 
        CampoVettoriale CampoGravitazionale(const Posizione&) const;



};

#endif 