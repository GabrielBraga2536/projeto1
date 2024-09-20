#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Lampada: public Atuador{
    private:
        bool brilho;

    public:
        Lampada(bool brilho){
        this->brilho = brilho;
        }

        bool setBrilho(bool brilho){
            if(brilho >= 1){
                return true;
            }

            else{
                return false;
            }
        }

        bool getBrilho(){
            return brilho;
        }

};