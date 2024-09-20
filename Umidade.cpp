#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador: public Atuador{
    private:
        bool configuracao;

    public:
        Umidificador(bool configuracao){
        this->configuracao = configuracao;
        }

        bool setUmidificador(bool configuracao){
            if(configuracao >= 1){
                return true;
            }

            else{
                return false;
            }
        }

        bool getUmidificador(){
            return configuracao;
        }

};