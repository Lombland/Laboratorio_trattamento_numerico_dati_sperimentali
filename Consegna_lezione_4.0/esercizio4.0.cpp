#include "funzioni.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"

using namespace std; 

int main(  ) {

  TApplication app("app",0,0);

  TGraphErrors trend;

  int index{0};

    for ( int i = 1941 ; i < 2024 ; i++) {
    string filename = to_string(i) + ".txt" ;
    vector<double> v = Read<double> ( filename.c_str() ) ;
    double ave = calcola_media<double>(v);
    double var = calcola_varianza<double>(v);
    double err = sqrt(var);

    cout << "  Anno " << to_string(i) << "  delta medio = " << ave << " +/- " << err <<  endl;

    // inserisco media e deviazione standard dalla media nel grafico 

    trend.SetPoint(index, i, ave);
    trend.SetPointError( index , 0 , err);

    index++;

  }

  TCanvas c("Temperature trend","Temperature trend");
  c.cd();
  c.SetGridx();
  c.SetGridy();

  trend.SetMarkerSize(1.0);
  trend.SetMarkerStyle(20);
  trend.SetFillColor(5);

  trend.SetTitle("Temperature trend");
  trend.GetXaxis()->SetTitle("Anno");
  trend.GetYaxis()->SetTitle("#Delta (#circ C)");
  trend.Draw("apl3");
  trend.Draw("pX");

  c.SaveAs("trend.pdf");

  app.Run();

}

