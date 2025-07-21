#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "RandomGen.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std; 

double Media (vector<double>);
double Var (vector<double>);

int main(int argc, char** argv){

    TApplication myApp ("myApp",0,0);

    if (argc != 2) {
        cout << "Utilizzo: " << argv[0] << " <N>" << endl;
        exit(-1);
    }

    int N = atoi(argv[1]);

    if (N <= 0) {
        cout << "Errore: <N> deve essere un numero intero positivo." << endl;
        exit(-1);
    }

    RandomGen gen(1);
    const int nmax = 10000;

    TH1F numeri("Numeri","Numeri",50,0,1);
    TH1F somme("Somme","Somme",50,0,N);
    TGraph errore("Errore","Errore");

    for(int i=0; i<nmax; i++){
        vector<double> num; 
        double sum{0}; 
        for(int j=0; j<N; j++){
            double appo{gen.Rand()};
            num.push_back(appo);
            sum += appo; 
            numeri.Fill(appo);
        }
        somme.Fill(sum);
    }

    TCanvas c; 
    c.Divide(2,1); 

    c.cd(1); 
    numeri.Draw();

    c.cd(2);
    somme.Draw();

    c.Update();

    myApp.Run();
}

double Media (vector<double> X){
    double sum {0};
    for(int i=0; i<X.size(); i++){
        sum+=X[i]; 
    }
    return (sum/X.size());
}

double Var (vector<double> X){
    double sum{0};
    double med =  Media(X); 
    for(int i=0; i<X.size(); i++){
        sum += pow(X[i]-med, 2);
    }
    return (sum/X.size()); 
}