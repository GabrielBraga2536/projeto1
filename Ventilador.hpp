#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Ventilador: public Atuador{
    private:
        int velocidade;

    public:
        Ventilador(int velocidade){
            this->velocidade = velocidade;
        }

        void setVelocidade(int velocidade){
            if (velocidade >= 1){
                velocidade = 1;
            }

            else{
                velocidade = 0;
            }
        }


};