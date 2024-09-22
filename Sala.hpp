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
        Sala(bool velocidade, bool configuracao, bool estado, bool brilho) : 
            ventilador{velocidade}, desumidificador{configuracao}, umidificador{estado}, lampada{brilho}, luminosidade{brilho}, temperatura{velocidade}, umidade{configuracao, estado}{}

        bool getVelocidadeVentilador(){
            return ventilador.getVelocidade();
        }

        void setVentiladorVelocidade(bool novaVelocidade) {
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

        bool getBrilho(){
            return luminosidade.estaClaro();
        }

        bool getLampada(){
            return lampada.getLampadaEstado();
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

        bool getConfiguracaoUmidificador(){
            return umidificador.getUmidificador();
        }

        float getUmidade(){
            return umidade.getUmidadeRelativa();
        }

        void setConfiguracaoUmidificador(bool novoEstado) {
                umidificador.setUmidificador(novoEstado); 
        }

};