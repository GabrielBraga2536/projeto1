#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Umidade: public Sensor{
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