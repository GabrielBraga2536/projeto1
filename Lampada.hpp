#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Lampada: public Atuador{
    private:
        int brilho;

    public:
        Lampada(int brilho){
        this->brilho = brilho;
        }

        bool setBrilho(int brilho){
            if(brilho >= 1){
                return true;
            }

            else{
                return false;
            }
        }



};