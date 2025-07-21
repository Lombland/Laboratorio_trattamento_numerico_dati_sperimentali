#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "RandomGen.h"

#include <iostream>
#include <vector>

using namespace std; 

double devStd(vector<double> , int);
double med(vector<double>, int);

int main(int argc, char**argv){

    if( argc != 2){
        cout<<"Inserire "<<argv[0]<< "<N>"<<endl; 
        return -1; 
    }

    double N = atoi(argv[1]);
    double nsteps = 100000; 

    TApplication myApp ("myApp",0,0);

    RandomGen Gen(1); 

    vector<double> Rand;

    for (int i=0; i<N; i++){
        double appo = Gen.Rand();
        Rand.push_back(appo);
    }

    double Med = med(Rand, N);
    double Dev_Std = devStd(Rand, N);

    TH1F hRandom("hRandom", "Numeri casuali uniformi [0,1]", 50, 0, 1);
    TH1F hSums("hSums", "Somma di N numeri casuali", 50, 0, N);

        double sum {0.}; 
        for(int k=0; k<N; k++){
            double appo = Gen.Rand(); 
            hRandom.Fill(appo);
            sum += appo;
            hSums.Fill(sum);
        }
 

    TCanvas canvas {"Limite centrale","Limite centrale", 800,600};
    canvas.Divide(2,1);
    
    canvas.cd(1);
    hRandom.GetXaxis()->SetTitle("");
    hRandom.GetYaxis()->SetTitle("");
    hRandom.Draw("HIST");

    canvas.cd(2);
    hSums.GetXaxis()->SetTitle("");
    hSums.GetYaxis()->SetTitle("");
    hSums.Draw("HIST");
    
    canvas.Update();

    myApp.Run();


}

double med(vector<double> X, int N){
    double sum {0};
    for(int i=0; i<N; i++){
        sum += X[i];
    }
    return sum/N;
}

double devStd(vector<double> X, int N){
    double sum; 
    double Med = med(X, N); 
    for(int i=0; i<N; i++){
        sum = pow(2, Med-X[i]);
    }
    return sqrt(sum/N);
}