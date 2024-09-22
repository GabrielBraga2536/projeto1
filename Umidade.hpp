#pragma once
#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Umidade: public Sensor{
    private:
        float umidadeRelativa;
        float umido;
        bool configuracao;
        bool estado;

    public:
        Umidade(string nome, bool ligado, bool conectado, int valor, int numero, float umidadeRelativa, bool configuracao, bool estado): Sensor(nome, ligado, conectado, valor, numero), umidadeRelativa{umidadeRelativa}, configuracao{configuracao}, estado{estado}{}

        float getUmidadeRelativa(){
            if(estado == 1){
                umido = umidadeRelativa + 0.5;
            }
            if(configuracao == 1){
                umido = umidadeRelativa - 0.5;
            }
            return umido;
        }

        void getUmidificador(bool estado){
            this->estado = estado;
        }
        
        void getDesumidificador(bool configuracao){
            this->configuracao = configuracao;
        }
};