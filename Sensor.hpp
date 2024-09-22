#pragma once
#include <iostream>
#include "Componente.hpp"
using namespace std;

class Sensor: public Componente{
    private:
        int numero;

    public:
        Sensor(string nome, bool ligado, bool conectado, int valor, int numero): Componente(nome, ligado, conectado, valor), numero{numero}{}

    void setNumero(int numero){
        this->numero = numero;
    }
};