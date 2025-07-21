#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std; 

template <typename T> vector<T> Read(const char* filename){
    vector<T> v;
    ifstream in(filename);
    if(!in){
        cout<<"Errore caricamento file"<<endl;
        exit(11);
    }else{
            T val;
            in >> val;
            v.push_back(val);
            if(in.eof()){
                cout<<"caricamento file completato"<<endl;
            }
    }
    return v;
}


template <typename T> void Print(const vector<T> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout<<i+1<<") "<<v.at(i)<<endl;
    }
}  

template <typename T> T calcola_media(const vector<T>& v) {
    double sum = 0;
    for (size_t i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }
    return sum / v.size();
}

template <typename T> T calcola_varianza(vector<T> v){
    double sumQuad = 0;
    T media =  calcola_media(v);
    double cont {0}; 
    for(unsigned int i=0; i<v.size(); i += 7){
        sumQuad += pow((media-v.at(i)),2);
        cont++; 
    }
    return sumQuad/cont;
}

template <typename T> T calcola_mediana(vector<T> v){
    sort(v.begin(), v.end());
    double mediana = 0;
    if ( v.size() %2 == 0 ) {    
        mediana = ( v.at(v.size() /2 -1 ) + v.at(v.size()/2)  ) /2.;    
    } else {
        mediana = v.at(v.size() /2);    
    }
    return mediana;
}