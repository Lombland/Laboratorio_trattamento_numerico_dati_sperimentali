#include "EquazioniDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TMarker.h"

string convert (double h);

int main (int argc, char**argv){

    if(argc != 2){
        cerr<<"Inserire il passo: "<<argv[0]<<"<stepsize>"<<endl; 
    }

    TApplication myApp("myApp",0,0);

    RougeKutta RK; 
    OscillatoreArmonico oscillatore(1.);

    double tmax = 70.;
    double h = atof(argv[1]);
    vector<double> x{0., 1.}; 
    double t = 0.; 
    
 
    int nstep = int(tmax/h+0.5);  

    TGraph myGraph;
    for (int i = 0; i < nstep; i++) {
    myGraph.SetPoint(i, t, x[0]);
    x = RK.Passo(t, x, h, oscillatore);
    t = t + h;
    }

    TCanvas c;
    c.cd();
    c.SetGridy();

    string title = "Oscillatore armonico (RougeKutta h = )" +convert(h)+")";
    myGraph.SetTitle(title.c_str());
    myGraph.GetXaxis()->SetTitle("Tempo[s]");
    myGraph.GetYaxis()->SetTitle("Posizione x[m]");
    myGraph.Draw("AL");
    c.Update();



    TGraph Error; 


    for (unsigned int i = 0; i < 10; i++) {
        h = 0.1 * pow(0.5, i);
        t = 0;
        x = {0., 1.};  // Reinizializza x
        nstep = int(tmax / h + 0.5);

        for (unsigned int step = 0; step < nstep; step++) {
        x = RK.Passo(t, x, h, oscillatore);
        t = t + h;
        }

        double eps = fabs(x[0] - sin(t));
        Error.SetPoint(i, h, eps);
    }

    TCanvas e;
    e.cd();
    e.SetGridy();
    e.SetGridx(); 

    string title_error = "Errore Oscillatore armonico (RougeKutta)";
    Error.SetTitle(title_error.c_str());
    gPad->SetLogx();
    Error.GetXaxis()->SetTitle("Passo integrazione h[s]");
    gPad->SetLogy(); 
    Error.GetYaxis()->SetTitle("Errore [m]");
    Error.SetMarkerStyle(20);
    Error.SetMarkerSize(0.5);
    Error.Draw("ALP");
    e.Update(); 

    myApp.Run(); 
    
}

string convert (double h){
    int cifre_significative = -log10(h);
    ostringstream streamObj3;
    streamObj3 << fixed;
    streamObj3 << setprecision(cifre_significative);
    streamObj3 << h;
    string strObj3 = streamObj3.str();
    return strObj3;
};