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

    unsigned int nmax = 10000; 

    Funzioni F;
    IntegratoreMedia Gen(1);
    vector<unsigned int> cases = {500, 1000, 5000, 10000, 50000, 100000};

    for (unsigned int i = 0; i < cases.size(); i++) {
        string filename = to_string(i + 1) + ".txt";
        ofstream out(filename);
        if (!out.is_open()) {
            cerr << "Errore apertura del file " << filename << endl;
            return -1;
        }

        for (unsigned int k = 0; k < nmax; k++) {
            double appo = Gen.Integra(F, 0, M_PI / 2, cases[i], 1.0);
            out << appo << endl;
        }

        out.close();
        cout << "File " << filename << " creato correttamente" << endl;
    }

    return 0;
}
