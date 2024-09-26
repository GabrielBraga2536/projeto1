#include <iostream>
#include "Sensor.hpp"
#include "Defeitos.hpp"
using namespace std;

class Temperatura: public Sensor{
    private:
        float temperaturaEmC;
        float temperaturaEmF;
        float temperaturaEmK;
        float temperatura;
        float temperaturaNova;
        int velocidade;
        float ajuste;

    public:
        //Construtor da "Temperatura", indicando se o atuador que esse sensor está detectando está ligado ou desligado, conectado ou desconectado e o qual o valor atual desse atuador
        Temperatura(string nome, bool ligado, bool conectado, int valor, int numero, int velocidade, float temperatura): Sensor(nome, ligado, conectado, valor, numero), temperatura{temperatura}, velocidade{velocidade}{}

        //Função para alterar a velocidade
        void setNovaVelocidade(int velocidade){
            this->velocidade = velocidade;
        }

        //Função para alterar a temperatura
        void setNovaTemperatura(){
            temperaturaNova = temperatura;
            if (velocidade > 2){
                temperaturaNova = temperaturaNova - (float)(getNumero()%431)/100; 
            }
            else if (velocidade == 2){
                temperaturaNova = temperaturaNova - (float)(getNumero()%167)/100; 
            }
            else if (velocidade == 1){
                temperaturaNova = temperaturaNova - (float)(getNumero()%29)/100; 
            }
            else {
                temperaturaNova = temperaturaNova + (float)(getNumero()%29)/100;
            }

            if(temperaturaNova > 35){
                temperaturaNova = 35;
                temperaturaNova = temperaturaNova + (float)(getNumero()%11)/100;
            }
            else if (temperaturaNova < 10){
                temperaturaNova = 9.99;
                temperaturaNova = temperaturaNova - (float)(getNumero()%11)/100;
            }
            temperatura = temperaturaNova;
        }

        //Função para informar o valor da temperatura em Celsius
        float getTemperaturaEmC(){
            temperaturaEmC = temperatura;
            return temperaturaEmC;
        }
        //Função para informar o valor da temperatura em Faherenheit
        float getTemperaturaEmF(){
            temperaturaEmF = (temperatura * 9/5) + 32;
            return temperaturaEmF;
        }
        //Função para informar o valor da temperatura em Kelvin
        float getTemperaturaEmK(){
            temperaturaEmK = temperatura + 273.15;
            return temperaturaEmK;
            ajuste = 1;
            velocidade = 1;
        }
};