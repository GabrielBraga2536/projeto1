#pragma once
#include <iostream>
#include "Atuador.hpp"
#include "Sensor.hpp"
using namespace std;

class Sala{
    private:
        Sensor sensor;
        Atuador atuador;

    public:
        Sala s1(float temperaturaEmC, float luminosidade, float umidade, int velocidade, bool configuracao, int brilho): temperaturaEmC{temperaturaEmC},luminosidade{luminosidade},umidade{},velocidade{velocidade}, configuracao{configuracao}, brilho{brilho}{}
        
        void atualizarSensores(){
            this->sensores = sensores;
        }

        void atualizarAtuadores(){
            this->atuadores = atuadores;
        }

};