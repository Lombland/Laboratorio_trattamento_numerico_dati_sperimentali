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

int main(){

    Funzioni F;
    IntegratoreMedia IntMC(1); 
    vector<double> cases = {500, 1000, 5000, 10000, 50000, 100000};

    for (unsigned int i = 0; i < cases.size(); i++) {
        unsigned int nmax = 1000000;
        string nomefile = to_string(i+1);
        ofstream f(nomefile);

        if (!f.is_open()) {
            cerr << "Errore nell'aprire il file " << nomefile << endl;
            return 1;
        }

        for (unsigned int k = 0; k < nmax; k++) {
            double risultato = IntMC.Integra(F, 0, M_PI / 2, cases[i], 0);
            f << risultato << "\n"; 
        }

        f.close();
        cout << "Risultati salvati in " << nomefile << endl;
    }

    return 0;
}