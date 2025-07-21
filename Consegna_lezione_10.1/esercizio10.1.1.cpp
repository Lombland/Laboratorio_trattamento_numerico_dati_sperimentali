#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "RandomGen.h"

#include <iostream>
#include <vector>

using namespace std; 

double Media (vector<double>);
double Var (vector<double>);

int main(){

    TApplication myApp("myApp",0,0);
    vector<double> cases;
    for(int i{1}; i<=12; i++){
        cases.push_back(i);
    }

    RandomGen gen(1);
    int nmax{100000};

    vector<TH1F*> histos; 
    vector<double> num; 
    vector<double> devstd;

    for(int i{0}; i<cases.size(); i++){
        TH1F* h = new TH1F("somme","somme",100,0,cases[i]);
        for(int j{0}; j<nmax; j++){
            double sum{0};
            vector<double> num; 
            double var{0};
            for(int k{0}; k<cases[i]; k++){
                double appo{gen.Rand()};
                sum+=appo;
                num.push_back(appo);
            }
            h->Fill(sum);
        }
        histos.push_back(h);
        double Dev_Std = sqrt(Var(num));
        devstd.push_back(Dev_Std);
    }

    TCanvas c; 
    c.Divide(3,4);

    for(int i{0}; i<cases.size(); i++){
        c.cd(i+1);
        histos[i]->Draw();
    }

    c.Update();

    TGraph* Dev = new TGraph(cases.size());
    for(int i{0}; i<cases.size(); i++){
        Dev->SetPoint(i, cases[i], devstd[i]);
    }

    TCanvas cdev;
    cdev.SetLogy();
    Dev->GetYaxis()->SetTitle("sigma");
    Dev->GetXaxis()->SetTitle("N");
    Dev->Draw("ALP");
   
    cdev.Update();

    myApp.Run();

    for(auto h:histos){
        delete h;
    }

    delete Dev;

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