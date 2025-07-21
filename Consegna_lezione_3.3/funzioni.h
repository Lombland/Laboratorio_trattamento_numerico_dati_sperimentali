#include <vector> 
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std; 

template <typename T> vector<T> Read(int N, const char* filename){
    vector<T> v;
    ifstream in(filename);
    if(!in){
        cout<<"Errore caricamento file"<<endl;
        exit(11);
    }else{
        for(unsigned int i=0; i<N; i++){
            T val;
            in >> val;
            v.push_back(val);
            if(in.eof()){
                cout<<"caricamento file completato"<<endl;
            }
        }
    }
    return v;
}

template <typename T> void Print(const vector<T> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout<<i+1<<") "<<v.at(i)<<endl;
    }
}  

template <typename T> T calcola_media(vector<T> v){
    double sum = 0;
    for(unsigned int i=0; i<v.size(); i++){
        sum += v.at(1);
    }
    return sum/v.size();
}

template <typename T> T calcola_varianza(vector<T> v){
    double sumQuad = 0;
    T media =  calcola_media(v);
    for(unsigned int i=0; i<v.size(); i++){
        sumQuad = pow((media-v.at(i)),2);
    }
    return sumQuad;
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