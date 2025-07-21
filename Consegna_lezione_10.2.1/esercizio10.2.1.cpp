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
    TApplication myApp("myApp",0,0); 

    unsigned int nmax = 1000000;

    Funzioni F; 
    IntegratoreMedia IntMC(1);

    vector<string> cases = {"1","2","3","4","5","6"}; 
    vector<unsigned int> N = {500,1000,5000,10000,50000,100000};
    vector<TH1F*> vhistos; 

    for(unsigned int i=0; i<cases.size(); i++){
        ifstream in(cases[i]);
        if(!in.is_open()){
            cerr<<"Errore apertura file : "<<cases[i]<<endl;
            return -1;
        }
        string filename = "N = "+to_string(N[i]);
        TH1F* h = new TH1F(filename.c_str(),filename.c_str(),30,0,1);
        double appo; 
            for(unsigned int k=0; k<N[i]; k++){
            while(in >> appo)
                h->Fill(appo);
            } 
        vhistos.push_back(h); 
        in.close();
    }

    TCanvas c;
    c.Divide(3,2); 

    for(int i=0; i<vhistos.size(); i++){
        c.cd(i+1);
        vhistos[i]->Draw();
    }

    c.Update(); 
    myApp.Run();

    for(int i=0; i<vhistos.size(); i++){
        delete vhistos[i];
    }
}