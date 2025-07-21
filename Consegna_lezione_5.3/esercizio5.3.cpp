#include "CampoVettoriale.h"
#include "PuntoMateriale.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std; 

int main(int argc, char** argv){

    if ( argc!= 4) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    exit(-1);
    }

    const double e =1.60217653E-19 ;
    const double me=9.1093826E-31;
    const double mp=1.6726219E-27;  
    const double d =1.E-10;

    PuntoMateriale elettrone(me, -e, 0,0,d/2);
    PuntoMateriale protone(mp,e,0,0, -d/2);

    Posizione p (atof(argv[1]), atof(argv[2]), atof(argv[3]));

    CampoVettoriale E = elettrone.CampoElettrico(p) + protone.CampoElettrico(p);

    cout<<"Campo elettrico generato dal dipolo: "<<endl;
    cout<<"E= ("<<E.GetFx()<<" ,"<<E.GetFy()<<" ,"<<E.GetFz()<<")"<<endl;

    return 0;
}