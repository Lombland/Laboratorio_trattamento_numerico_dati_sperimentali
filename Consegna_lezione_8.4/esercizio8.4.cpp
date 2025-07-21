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

using namespace std; 

string convert (double h);

int main() {
    TApplication myApp("myApp", 0, 0); 

    RougeKutta RK;

    double omega0 = 10; 
    double alpha = (1. / 30.);
    vector<double> omega; 
    double start = 9.0, end = 11.0, step = 0.05;
    for (double value = start; value <= end; value += step) {
        omega.push_back(value);
    }

    double h = 0.01; 
    double tmax = 300; 
    double nstep = int(tmax / h + 0.5);

    // Crea una finestra principale
    TCanvas *canvas = new TCanvas("Moto", "Oscillatore Armonico Forzato", 1200, 1200);
    canvas->Divide(5, 8); // Divide la finestra in 5 colonne e 8 righe (5x8 = 40).

    for (size_t j = 0; j < omega.size(); j++) {
        OscillatoreForzato osc(omega0, omega[j], alpha);
        TGraph *moto = new TGraph();

        double t = 0; 
        vector<double> x{0., 0.}; 

        for (int i = 0; i < nstep; i++) {
            x = RK.Passo(t, x, h, osc); 
            moto->SetPoint(i, t, x[0]);
            t += h; 
        }

        // Seleziona il pad corrispondente
        canvas->cd(j + 1);

        // Disegna il grafico
        string title_error = "Oscillatore armonico smorzato (pulsazione forzante = "+convert(omega[j])+")";
        moto->SetTitle(title_error.c_str());
        moto->SetLineColor(kBlue);
        moto->SetLineWidth(2);
        moto->SetTitle(("Omega = " + to_string(omega[j])).c_str());
        moto->Draw("ALP");

        // Configura gli assi
        moto->GetXaxis()->SetTitle("Tempo [s]");
        moto->GetYaxis()->SetTitle("Posizione [m]");
    }

    canvas->Update();
    myApp.Run();

    return 0;
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