#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Temperatura: public Sensor{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;

    public:
        Temperatura(float temperaturaEmC): temperaturaEmC{temperaturaEmC}{}

        float getTemperaturaEmC(){
            return temperaturaEmC;
        }

        float getTemperaturaEmF(){
            temperaturaEmF = (temperaturaEmC * 9/5) + 32;
            return temperaturaEmF;
        }

        float getTemperaturaEmK(){
            temperaturaEmK = temperaturaEmC + 273.15;
            return temperaturaEmK;
        }
};