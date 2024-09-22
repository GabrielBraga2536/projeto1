#pragma once
#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Luminosidade: public Sensor{
    private:
        int limitarClaridade(){
            return luminosidade;
        }

        float luminosidade;
        int brilho;

    public:
        Luminosidade(string nome, bool ligado, bool conectado, int valor, int numero, int brilho, float luminosidade): Sensor(nome, ligado, conectado, valor, numero), luminosidade{luminosidade}, brilho{brilho}{}

        bool estaClaro(){
            if(getValorAtuador() >= 1){
                brilho = 1;
            }
            else{
                brilho = 0;
            }
            return brilho;
        }
};