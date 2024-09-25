#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Ventilador: public Atuador{
    private:
        int velocidade;

    public:
        //Construtor do "Ventilador", indicando se esse atuador está ligado ou desligado, conectado ou desconectado e o valor atual desse atuador
        Ventilador(string nome, bool ligado, bool conectado, int valor, float conta, int velocidade):Atuador(nome, ligado, conectado, valor, conta), velocidade{velocidade}{}
        //Função para alterar a velocidade do Ventilador (provavelmente será removido, pois isso é alterado pelo valore de "valor")
        void setVelocidade(int velocidade){
            this->velocidade = velocidade;
        }
        //Função para informar a velocidade do Ventilador
        int getVelocidade(){
            if (getValorAtuador() >= 1){
                return true;
            }

            else{
                return false;
            }
        }


};