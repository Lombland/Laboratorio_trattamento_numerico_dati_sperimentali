#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "RandomGen.h"

#include <iostream>

using namespace std; 

int main(){

    TApplication myApp ("myApp",0,0);

    int nmax = 10000; 

    RandomGen Gen(1); 

    TH1F unif("Uniforme", "Uniforme", 70, 5, 10);
    TH1F Exp("Esponenziale", "Esponenziale", 70, 0, 10);
    TH1F Gaus("Gaussiana Box-Muller", "Gaussiana Box-Muller", 70, -5, 5);
    TH1F GausAR("Gaussiana Accept-Reject", "Gaussiana Accept-Reject", 70, -5, 5);

    for(int i = 0; i<nmax; i++){
        double randUnif = Gen.Unif(5., 10.);
        double randExp = Gen.Exp(1.);
        double randGaus = Gen.Gaus(1., 1.);
        double randGausAR = Gen.GausAR(1., 1., 0.4);

        unif.Fill(randUnif);
        Exp.Fill(randExp);
        Gaus.Fill(randGaus);
        GausAR.Fill(randGausAR);
    }

    TCanvas canvas("Distribuzioni", "Distribuzioni", 800, 600);
    canvas.Divide(2, 2);

    canvas.cd(1);
    unif.GetXaxis()->SetTitle("");
    unif.GetYaxis()->SetTitle("");
    unif.Draw("HIST");

    canvas.cd(2);
    Exp.GetXaxis()->SetTitle("");
    Exp.GetYaxis()->SetTitle("");
    Exp.Draw("HIST");

    canvas.cd(3);
    Gaus.GetXaxis()->SetTitle("");
    Gaus.GetYaxis()->SetTitle("");
    Gaus.Draw("HIST");

    canvas.cd(4);
    GausAR.GetXaxis()->SetTitle("");
    GausAR.GetYaxis()->SetTitle("");
    GausAR.Draw("HIST");

    canvas.Update();

    myApp.Run();

}