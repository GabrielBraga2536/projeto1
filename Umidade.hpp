#pragma once
#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Umidade: public Sensor{
    private:
        float umidadeRelativa;
        float umidade;
        bool configuracao;
        bool estado;

    public:
        //Construtor da "Umidade", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Umidade(string nome, bool ligado, bool conectado, int valor, int numero, float umidadeRelativa, bool configuracao, bool estado): Sensor(nome, ligado, conectado, valor, numero), umidadeRelativa{umidadeRelativa}, configuracao{configuracao}, estado{estado}{}
    
        //Informa a umidade relativa do sensor
        float getUmidadeRelativa(){
            return umidadeRelativa;
        }

        void setConfiguracaoDesumidificador(bool configuracao){
            this->configuracao = configuracao;
        }

        void setConfiguracaoUmidificador(bool estado){
            this->estado = estado;
        }

        //Função para alterar a umidade
        void setNovaUmidade(){
            umidade = umidadeRelativa;
            if (configuracao > 0){
                umidade = umidade - (float)(getNumero()%37)/100; 
            }
            if (estado > 0) {
                umidade = umidade + (float)(getNumero()%37)/100;
            }

            if(umidade > 60){
                umidade = 60;
                umidade = umidade + (float)(getNumero()%3)/100;
            }
            else if (umidade < 40){
                umidade = 39.99;
                umidade = umidade - (float)(getNumero()%3)/100;
            }
            umidadeRelativa = umidade;
        }
};