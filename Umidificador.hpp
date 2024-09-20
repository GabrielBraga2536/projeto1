#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador: public Atuador{
    private:
        int estado;

    public:
        Umidificador(int estado){
        this->estado = estado;
        }

        bool setUmidificador(int estado){
            if(estado >= 1){
                return true;
            }

            else{
                return false;
            }
        }

};