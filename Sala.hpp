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


        Sala(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, bool brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade) : 
            ventilador{nome, ligado, conectado, valor, conta, velocidade}, 
            desumidificador{nome, ligado, conectado, valor, conta, configuracao}, 
            umidificador{nome, ligado, conectado, valor, conta, estado, ajuste}, 
            lampada{nome, ligado, conectado, valor, conta, brilho, intensidade}, 
            luminosidade{nome, ligado, conectado, valor, numero, brilho, luminosidade}, 
            temperatura{nome, ligado, conectado, valor, numero, velocidade}, 
            umidade{nome, ligado, conectado, valor, numero, umidadeRelativa, configuracao, estado}{}

        bool getVelocidadeVentilador(){
            return ventilador.getVelocidade();
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

        bool getConfiguracaoDesumidificador(){
            return desumidificador.getDesumidificador();
        }

        bool getConfiguracaoUmidificador(){
            return umidificador.getUmidificador();
        }

        float getUmidade(){
            return umidade.getUmidadeRelativa();
        }

        void setVelocidadeVentilador(int novaVelocidade) {
                ventilador.setVelocidade(novaVelocidade); 
        }

        void setEstadoUmidificador(bool novoEstado) {
                umidificador.setUmidificador(novoEstado); 
        }
        
        void setConfiguracaoDesumidificador(bool novaConfiguracao) {
                desumidificador.setDesumidificador(novaConfiguracao); 
        }
        
        void setBrilhoLampada(bool novoBrilho) {
                lampada.setBrilho(novoBrilho); 
        }
};