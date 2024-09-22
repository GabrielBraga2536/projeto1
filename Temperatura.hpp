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
            temperaturaEmC = getValorAtuador();
            return temperaturaEmC;
        }

        float getTemperaturaEmF(){
            temperaturaEmC = getValorAtuador();
            temperaturaEmF = (temperaturaEmC * 9/5) + 32;
            return temperaturaEmF;
        }

        float getTemperaturaEmK(){
            temperaturaEmC = getValorAtuador();
            temperaturaEmK = temperaturaEmC + 273.15;
            return temperaturaEmK;
        }

        void getVelocidade(int velocidade){
            ajuste = 1;
            this->velocidade = velocidade;
        }
};