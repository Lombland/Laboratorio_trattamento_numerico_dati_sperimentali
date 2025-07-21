#include "EquazioniDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TMarker.h"

int main(int argc, char** argv){

    TApplication myApp("myApp",0,0);

    double g = 9.8067;
    double l = 1;

    double omega0 = -(g/l);

    RougeKutta RK;
    Pendolo osc(omega0);

    double h = 0.1; 
    int nsteps = 30;

    TGraph periodo; 
    TGraph differenza; 

    for(int i=0; i<nsteps;i++){
        
        
        double A = 0.1*(i+1);

        double v = 0;
        double t = 0; 

        vector <double> x{-A, v};
        vector <double> x_next;


        
        while (x[1]>=0) {
            v = x[1];
            x = RK.Passo(t,x,h,osc);
            t += h;
            cout<<A<<" "<<x[0]<<" "<<t<<endl;
        }
    


        t = t-v*h/(x[1]-v);
     
        periodo.SetPoint(i, A,(2*t));
        

    }

    TCanvas canvas ("Periodo","Periodo in funzione del passo", 600,600);

    periodo.GetXaxis()->SetTitle("Ampiezza[m]");
    periodo.GetYaxis()->SetTitle("Periodo[s]");
    periodo.SetMarkerStyle(20);
    periodo.SetMarkerSize(1.5);
    periodo.Draw("ALP");
    canvas.Update();

    myApp.Run(); 
}