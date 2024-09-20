#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Luminosidade{
    private:
        int limitarClaridade(){
            return luminosidade;
        }
        float luminosidade;

    public:
        Luminosidade( float luminosidade){
        this->luminosidade = luminosidade;
        }

        bool estaClaro(){
            if(brilho == 1){
                return true;
            }
        
            else{
                return false;
            }
        }

        void setLimiarClaridade(int luminosidade){
            this->luminosidade = luminosidade;
        }

        
};