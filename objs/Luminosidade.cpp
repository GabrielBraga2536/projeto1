#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Luminosidade: public Sensor{
    private:
        int limitarClaridade(){
            return luminosidade;
        }

        float luminosidade;

    public:
        Luminosidade(float luminosidade){
            this->luminosidade = luminosidade;
        }

        bool estaClaro(){
            if(luminosidade >= 1){
                return true;
            }

            else{
                return false;
            }
        }       
};