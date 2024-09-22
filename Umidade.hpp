#pragma once
#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Umidade: public Sensor{
    private:
        float umidadeRelativa;
        bool configuracao;
        bool estado;

    public:
        Umidade(string nome, bool ligado, bool conectado, int valor, int numero, float umidadeRelativa, bool configuracao, bool estado): Sensor(nome, ligado, conectado, valor, numero), umidadeRelativa{umidadeRelativa}, configuracao{configuracao}, estado{estado}{}

        float getUmidadeRelativa(){
            if(configuracao == 1){
                if(estado == 1){
                    return umidadeRelativa;
                }
            }
            umidadeRelativa = 12;
            return umidadeRelativa;
        }



};