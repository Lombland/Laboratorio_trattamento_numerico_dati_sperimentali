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

using namespace std; 

bool ChekValore(double val, const vector<double>& array, double epsilon);
string convert(double h);

int main() {
    TApplication myApp("myApp", 0, 0);

    RougeKutta RK;

    double omega0 = 10;
    double alpha = (1. / 30.);
    vector<double> omega;
    double start = 9.0, end = 11.0, step = 0.05;

    for (double value = start; value <= end + step / 2; value += step) {
        omega.push_back(value);
    }

    cout << "Valori di omega generati:\n";
    for (double v : omega) {
        cout << v << " ";
    }
    cout << "\n";

    double h = 0.01;
    double dumptime = 10. / alpha;
    double tmax = 300;
    double nstep = int(tmax / h + 0.5);

    TGraph moto;

    double val;
    const double epsilon = 1e-5;

    do {
        cout << "Inserisci un valore tra 9 e 11 con passo di 0.05: ";
        cin >> val;

        if (ChekValore(val, omega, epsilon)) {
            cout << "Valore valido inserito: " << val << "\n";
            break;
        } else {
            cout << "Valore non valido, riprova.\n";
        }
    } while (true);

    OscillatoreForzato osc(omega0, val, alpha);

    double t = 0;
    vector<double> x{0., 0.};

    for (int i = 0; i < nstep; i++) {
        x = RK.Passo(t, x, h, osc);
        moto.SetPoint(i, t, x[0]);
        t = t + h;
    }

    TCanvas c("Moto", "Oscillatore armonico forzato");
    c.cd();
    c.SetGridx();
    c.SetGridy();

    string title_error = "Oscillatore armonico smorzato (pulsazione forzante = " + convert(val) + ")";
    moto.SetTitle(title_error.c_str());
    moto.GetXaxis()->SetTitle("tempo[s]");
    moto.GetYaxis()->SetTitle("posizione[m]");
    moto.Draw("ALP");
    c.Update();

    myApp.Run();
}

bool ChekValore(double val, const vector<double>& array, double epsilon) {
    for (double v : array) {
        if (fabs(v - val) < epsilon) {
            return true;
        }
    }
    return false;
}

string convert(double h) {
    int cifre_significative = -log10(h);
    std::ostringstream streamObj3;
    streamObj3 << std::fixed;
    streamObj3 << std::setprecision(cifre_significative);
    streamObj3 << h;
    std::string strObj3 = streamObj3.str();
    return strObj3;
}
