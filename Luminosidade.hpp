#pragma once
#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Luminosidade: public Sensor{
    private:
        int limitarClaridade(){
            return luminosidade;
        }

        float luminosidade;
        int brilho;

    public:
        Luminosidade(int brilho){
            this->brilho = brilho;
        }

        bool estaClaro(){
            return brilho;
        }   
};