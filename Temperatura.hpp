#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Temperatura: public Sensor{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;
        int velocidade;

    public:
        Temperatura(int velocidade){
            this->velocidade = velocidade;
        }

        float getTemperaturaEmC(){
            temperaturaEmC = velocidade;
            return temperaturaEmC;
        }

        float getTemperaturaEmF(){
            temperaturaEmC = velocidade;
            temperaturaEmF = (temperaturaEmC * 9/5) + 32;
            return temperaturaEmF;
        }

        float getTemperaturaEmK(){
            temperaturaEmC = velocidade;
            temperaturaEmK = temperaturaEmC + 273.15;
            return temperaturaEmK;
        }

        bool getVelocidade(){
            if (velocidade >= 1){
                return true;
            }

            else{
                return false;
            }
        }
};