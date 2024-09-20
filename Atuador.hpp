#pragma once
#include <iostream>
using namespace std;

class Atuador: public Componente{
    private:
        int valor;

    public:

        bool setValor(int valor){
            if(valor == 1){
                return true;
            }
        
            else{
                return false;
            }
        }

};