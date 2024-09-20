#pragma once
#include <iostream>
#include "Atuador.hpp"
#include "Ventilador.hpp"
#include "Umidificador.hpp"
#include "Desumidificador.hpp"
#include "Lampada.hpp"
#include "Luminosidade.hpp"
#include "Umidade.hpp"
#include "Temperatura.hpp"
#include "Sensor.hpp"
using namespace std;

class Sala{
    private:
        Ventilador ventilador;
        Desumidificador desumidificador;
        Umidificador umidificador;
        Lampada lampada;
        Luminosidade luminosidade;
        Temperatura temperatura;
        Umidade umidade;

    public:
        Sala(int velocidade, int configuracao, int brilho, int estado) : 
            ventilador{velocidade}, desumidificador{configuracao}, umidificador{estado}, lampada{brilho}, luminosidade{brilho}, temperatura{velocidade}, umidade{configuracao, estado}{}

        bool getVelocidadeVentilador(){
            return temperatura.getVelocidade();
        }

        void setVentiladorVelocidade(int novaVelocidade) {
                ventilador.setVelocidade(novaVelocidade); 
        }

        float getTemperaturaC(){
            return temperatura.getTemperaturaEmC();
        }

        float getTemperaturaF(){
            return temperatura.getTemperaturaEmF();
        }

        float getTemperaturaK(){
            return temperatura.getTemperaturaEmK();
        }

        bool getBrilhoLampada(){
            return luminosidade.estaClaro();
        }

        void setBrilhoLampada(int novoBrilho) {
                lampada.setBrilho(novoBrilho); 
        }

        bool getConfiguracaoDesumidificador(){
            return umidade.getDesumidificador();
        }

        void setConfiguracaoDesumidificador(int novaConfiguracao) {
                desumidificador.setDesumidificador(novaConfiguracao); 
        }

        bool getConfiguracaoUmidificador(){
            return umidade.getUmidificador();
        }

        void setConfiguracaoUmidificador(int novoEstado) {
                umidificador.setUmidificador(novoEstado); 
        }

};