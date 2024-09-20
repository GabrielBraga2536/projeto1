#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Temperatura{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;
        float temperatura;

    public:
        Temperatura(float temperatura){
            this->temperatura = temperatura;
        }

        float getTemperaturaEmC(){
            return temperaturaEmC;
        }

        float getTemperaturaEmF(){
            return temperaturaEmF;
        }
        
        float getTemperaturaEmK(){
            return temperaturaEmK;
        }
};