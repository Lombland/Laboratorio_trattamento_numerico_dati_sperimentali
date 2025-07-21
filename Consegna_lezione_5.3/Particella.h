#ifndef __Particella_h__
#define __Particella_h__

class Particella{

    public:

    Particella();
    Particella(double massa, double carica);
    ~Particella();

    double GetMassa() const;
    double GetCarica() const; 
    void Print() const; 

    private: 
    double m_massa, m_carica; 

};

#endif 