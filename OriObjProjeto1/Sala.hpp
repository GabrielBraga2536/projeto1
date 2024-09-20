#pragma once
#include <iostream>
#include "Atuador.hpp"
#include "Sensor.hpp"
using namespace std;

class Sala{
    private:
        int atuadores;
        int sensores;

    public:

        void atualizarSensores(){
            this->sensores = sensores;
        }

        void atualizarAtuadores(){
            this->atuadores = atuadores;
        }

};