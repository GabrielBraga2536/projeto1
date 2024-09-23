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
        //Construtor da "Umidade", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Umidade(string nome, bool ligado, bool conectado, int valor, int numero, float umidadeRelativa, bool configuracao, bool estado): Sensor(nome, ligado, conectado, valor, numero), umidadeRelativa{umidadeRelativa}, configuracao{configuracao}, estado{estado}{}
        //Informa a umidade relativa do sensor
        float getUmidadeRelativa(){
            umido = umidadeRelativa;
            if(estado == 1){
                umido = umidadeRelativa + 0.5;
            }
            if(configuracao == 1){
                umido = umidadeRelativa - 0.5;
            }
            return umido;
        }
};