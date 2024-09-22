#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador: public Atuador{
    private:
        bool estado;
        bool ajuste;

    public:
        Umidificador(string nome, bool ligado, bool conectado, int valor, float conta, bool estado, bool ajuste):Atuador(nome, ligado, conectado, valor, conta), estado{estado}, ajuste{ajuste}{}

        void setUmidificador(bool estado){
            ajuste = 0;
            this->estado = estado;
        }

        bool getUmidificador(){
            return estado;
        }

};