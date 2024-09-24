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
        //Construtor da "Luminosidade", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Luminosidade(string nome, bool ligado, bool conectado, int valor, int numero, int brilho, float luminosidade): Sensor(nome, ligado, conectado, valor, numero), luminosidade{luminosidade}, brilho{brilho}{}
        
        //Função para o sensor informar se está claro ou escuro, ainda precisa criar a função para limitar a claridade do sensor
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