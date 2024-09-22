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
            umidadeRelativa = 12;
            return umidadeRelativa;
        }



};