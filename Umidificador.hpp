#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador: public Atuador{
    private:
        bool estado;

    public:
        Umidificador(bool estado){
        this->estado = estado;
        }

        bool setUmidificador(bool estado){
            if(estado >= 1){
                return true;
            }

            else{
                return false;
            }
        }

        bool getUmidificador(){
            return estado;
        }

};