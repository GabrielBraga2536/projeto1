#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Ventilador: public Atuador{
    private:
        int velocidade;

    public:
        Ventilador(string nome, bool ligado, bool conectado, int valor, float conta, int velocidade):Atuador(nome, ligado, conectado, valor, conta), velocidade{velocidade}{}

        void setVelocidade(int velocidade){
            this->velocidade = velocidade;
        }

        int getVelocidade(){
            if (velocidade >= 1){
                return true;
            }

            else{
                return false;
            }
        }


};