#include <iostream>
#include "Sala.hpp"
//#include "Componente.hpp"
#include "Atuador.hpp"
#include "Lampada.hpp"
#include "Desumidificador.hpp"
#include "Umidificador.hpp"
#include "Ventilador.hpp"
#include "Luminosidade.hpp"
using namespace std;

int main(){
//    Sala s1(float temperaturaEmC, float luminosidade, float umidade, int velocidade, bool configuracao, int brilho);

//    Sala s1(float 123, float 1, float 32, int 2, bool 1, int 2);

    Sala s1(1, 1, 0, 0);
    cout << "Lampada: " << s1.getBrilhoLampada() << endl;
    cout << "Desumidificador: " << s1.getConfiguracaoDesumidificador() <<endl;
    cout << "Umidificador: " << s1.getConfiguracaoUmidificador() <<endl;
    cout << "Ventilador: " << s1.getVelocidadeVentilador() <<endl;
    cout << "Temperatura em Celcius: " << s1.getTemperaturaC() <<endl;
    cout << "Temperatura em Fahrenheit : " << s1.getTemperaturaF() <<endl;
    cout << "Temperatura em Kelvin: " << s1.getTemperaturaK() <<endl;

//    s1.setVentiladorVelocidade(100);

//    cout << "Ventilador: " << s1.getVelocidadeVentilador() <<endl;

//    s1.setBrilhoLampada();
//    s1.setConfiguracaoDesumidificador();
//    s1.setConfiguracaoUmidificador();
//    s1.setVelocidadeVentilador();
}