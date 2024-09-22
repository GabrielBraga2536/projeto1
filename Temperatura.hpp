#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Temperatura: public Sensor{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;
        int velocidade;
        float ajuste;

    public:
        Temperatura(string nome, bool ligado, bool conectado, int valor, int numero, int velocidade): Sensor(nome, ligado, conectado, valor, numero), velocidade{velocidade}{}

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

        void setAjuste(float ajuste){
            this->ajuste = ajuste;
        }
};