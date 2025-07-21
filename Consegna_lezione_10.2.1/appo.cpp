#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "RandomGen.h"
#include "IntegraleMC.h"
#include "Funzioni.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std; 

int main() {
    TApplication myApp("App", 0, 0);

    unsigned int nmax = 10000;

    Funzioni F;
    IntegratoreMedia IntMC(1);

    vector<unsigned int> cases = {500, 1000, 5000, 10000, 50000, 100000};
    vector<TH1F*> vhistos; 

    for(unsigned int i{0}; i<cases.size(); i++){
        int N = cases[i]; 
        TH1F* h = new TH1F("","",50,0,cases[i]);
        for(unsigned int k=0; k<nmax; k++){
            double appo = IntMC.Integra(F, 0, M_PI/2, N, 0); 
            h->Fill(appo);
        }
        vhistos.push_back(h);
    }


    TCanvas c("Distribuzioni", "Distribuzioni", 1200, 800);
    c.Divide(3, 2);

    for (unsigned int i = 0; i < vhistos.size(); i++) {
        c.cd(i + 1);
        vhistos[i]->Draw();
    }

    c.Update();
    myApp.Run();

    return 0;
}