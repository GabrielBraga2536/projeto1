#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Ventilador: public Atuador{
    private:
        int velocidade;

    public:
        Ventilador(int velocidade){
        this->velocidade = velocidade;
        }

        bool setVelocidade(int velocidade){
            if (velocidade >= 1){
                return true;
            }

            else{
                return false;
            }
        }

        int getVelocidade(){
            return velocidade;
        }
};