#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidade: public Atuador{
    private:
        float umidadeRelativa;
        int configuracao;
        int estado;

    public:
        Umidade(int configuracao, int estado){
        this->configuracao = configuracao;
        this->estado = estado;
        }

        float getUmidadeRelativa(){
            return umidadeRelativa;
        }

        bool getUmidificador(){
            return estado;
        }

        bool getDesumidificador(){
            return configuracao;
        }

};