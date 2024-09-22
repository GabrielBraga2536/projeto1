#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Desumidificador: public Atuador{
    private:
        bool configuracao;

    public:
        Desumidificador(bool configuracao){
        this->configuracao = configuracao;
        }

        bool setDesumidificador(bool configuracao){
            if(configuracao == 0){
                return true;
            }

            else{
                return false;
            }
        }

        bool getDesumidificador(){
            return configuracao;
        }

};