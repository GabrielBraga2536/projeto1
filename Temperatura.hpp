#include <iostream>
#include "Sensor.hpp"
using namespace std;

class Temperatura: public Sensor{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;
        int velocidade;
        float ajuste;

    public:
        //Construtor da "Temperatura", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Temperatura(string nome, bool ligado, bool conectado, int valor, int numero, int velocidade): Sensor(nome, ligado, conectado, valor, numero), velocidade{velocidade}{}
        //Função para informar o valor da temperatura em Celsius
        float getTemperaturaEmC(){
            temperaturaEmC = getValorAtuador();
            return temperaturaEmC;
        }
        //Função para informar o valor da temperatura em Faherenheit
        float getTemperaturaEmF(){
            temperaturaEmC = getValorAtuador();
            temperaturaEmF = (temperaturaEmC * 9/5) + 32;
            return temperaturaEmF;
        }
        //Função para informar o valor da temperatura em Kelvin
        float getTemperaturaEmK(){
            temperaturaEmC = getValorAtuador();
            temperaturaEmK = temperaturaEmC + 273.15;
            return temperaturaEmK;
            ajuste = 1;
            velocidade = 1;
        }
};