#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Ventilador: public Atuador{
    private:
        bool velocidade;

    public:
        Ventilador(bool velocidade){
            this->velocidade = velocidade;
        }

//        bool setVelocidade(bool velocidade){
//            if (velocidade >= 1){
//                velocidade = 1;
//            }
//
//            else{
//                velocidade = 0;
//            }
//        }

        bool getVelocidade(){
            if (velocidade >= 1){
                return true;
            }

            else{
                return false;
            }
        }
};