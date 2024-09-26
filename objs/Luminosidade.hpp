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
        float luminosidadeNova;
        int brilho;

    public:
        //Construtor da "Luminosidade", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Luminosidade(string nome, bool ligado, bool conectado, int valor, int numero, int brilho, float luminosidade): Sensor(nome, ligado, conectado, valor, numero), luminosidade{luminosidade}, brilho{brilho}{}
        
        //Função para o sensor informar se está claro ou escuro, ainda precisa criar a função para limitar a claridade do sensor
        float estaClaro(){
            return luminosidade;
        }

        void setNovaLuminosidade(){
                luminosidadeNova = luminosidade;
            if (brilho <= 0){
                    luminosidadeNova = 10 - (float)(getNumero()%21)/100; 
            }
            else if (brilho == 1 ){
                    luminosidadeNova = 500 - (float)(getNumero()%211)/100;
            }
            else{
                    luminosidadeNova = 1000 - (float)(getNumero()%211)/100;
            }
                luminosidade = luminosidadeNova;
        }

        void setBrilhoNovo(int brilho){
            this->brilho = brilho;
        }
};