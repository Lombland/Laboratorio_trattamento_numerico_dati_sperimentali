#ifndef __Posizione_h__
#define __Posizione_h__

class Posizione{

    public: 
    //Distruttore 
    Posizione();
    Posizione(double x, double y, double z);

    //Costruttore 
    ~Posizione();

    //Metodi 
    double getX() const;
    double getY() const; 
    double getZ() const;
    double getR() const;
    double getPhi() const;
    double getTheta() const;
    double getRho() const; 

    double Distanza(const Posizione& ) const; 

    private:

    double m_x, m_y, m_z; 

};



#endif