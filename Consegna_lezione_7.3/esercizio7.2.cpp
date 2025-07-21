#include <iostream>
#include <cmath> 
#include <iomanip>
#include <cstdlib>

#include "Integral.h"
#include "Funzioni.h"
#include "Trapezio.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TGraph.h"


using namespace std; 

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Uso corretto: " << argv[0] << " <Precisione>" << endl;
        return -1;
    }

    double Prec = atof(argv[1]);
    if (Prec <= 0) {
        cout << "Errore: la precisione deve essere positiva" << endl;
        return -1;
    }

    unsigned int nstep;
    Funzioni f;
    Trapezio Intervallo(0, M_PI / 2);

    // Calcola l'integrale con precisione fissa
    double I = Intervallo.Integra(Prec, f, nstep);

    cout << "Risultato dell'integrale I = " << setw(20) << I << " con nPassi = " << setw(20) << nstep << endl;


    TApplication app("App",0,0);

    TGraph g_errore; 
    double Iv {1}; 
    double err{0}, h{0};
    double a{0}, b {M_PI/2};

    for(unsigned int k = 0; k<10; k++){

        h = (b-a)/nstep;
        I = Intervallo.Integra(nstep, f); 
        err = fabs(I-Iv); 
        cout <<"Numero passi= "<< setw(20) <<nstep<<"  err= "<<setw(20)<< err <<endl;
        g_errore.SetPoint(k, h, err); 
        nstep *= 2;

    }

    TCanvas c("Errore");
    c.cd();
    c.SetGridx();
    c.SetGridy();

    g_errore.SetMarkerSize(1.0);
    g_errore.SetMarkerStyle(20);
    g_errore.SetFillColor(5); 

    g_errore.SetTitle("Errore"); 
    g_errore.GetXaxis();
    g_errore.GetYaxis();
    gPad->SetLogy();  
    g_errore.Draw("apl3");
    gPad->SetLogx();
    g_errore.Draw("pX");

    c.SaveAs("Errore.pdf");

    app.Run();

    return 0;
}