#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Umidade{
    private:
        float umidade;

    public:
        Umidade(float umidade){
            this->umidade = umidade;
        }
        float getUmidaedeRelativa(){
            return umidade;
        }
};