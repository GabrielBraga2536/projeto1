#pragma once
#include <iostream>
#include "Atuador.hpp"
#include "Ventilador.hpp"
#include "Desumidificador.hpp"
#include "Lampada.hpp"
#include "Sensor.hpp"
using namespace std;

class Sala{
    private:
        Ventilador ventilador;
        Desumidificador desumidificador;
        Lampada lampada;

    public:
        Sala(bool velocidade, bool configuracao, bool brilho) : 
            ventilador{velocidade}, desumidificador{configuracao}, lampada{brilho}{}

        bool getVelocidadeVentilador(){
            return ventilador.getVelocidade();
        }

//        void setVentiladorVelocidade(bool novaVelocidade) {
//                ventilador.setVelocidade(novaVelocidade); 
//        }

        bool getBrilhoLampada(){
            return lampada.getBrilho();
        }

        void setBrilhoLampada(bool novoBrilho) {
                lampada.setBrilho(novoBrilho); 
        }

        bool getConfiguracaoDesumidificador(){
            return desumidificador.getDesumidificador();
        }

        void setConfiguracaoDesumidificador(bool novaConfiguracao) {
                desumidificador.setDesumidificador(novaConfiguracao); 
        }

//        void atualizarUmidificador(){
//this->configuracao = configuracao;
//}
//
//void atualizarDesumidificador(){
//this->configuracao = configuracao;
//}
//
//void atualizarLampada(){
//this->brilho = brilho;
//}

//bool getConfiguracaoUmidificador(){
//return configuracao;
//}
//
//bool getConfiguracaoDesumidificador(){
//return configuracao;
//}
//
//
//bool getBrilho(){
//return brilho;
//}
};