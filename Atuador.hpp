#pragma once
#include <iostream>
using namespace std;

class Atuador{
    private:
        int valor;

    public:
        // Atuador(int brilho){
        // this->brilho = brilho;
        // }

        bool setValor(int valor){
            this->valor = valor;
            return valor;
        }

};