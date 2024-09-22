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
//    Sala s1(bool velocidade, bool configuracao, bool estado, bool brilho);
//    Sala (define quais aparelhos estão ligados (ventilador, desumidificador, umidificador, lampada))

    Sala s1(0, 0, 0, 1);
    //velocidade do ventilador que define os valores do sensor das temperaturas
    cout << "Ventilador: " << s1.getVelocidadeVentilador() <<endl;
    cout << "Temperatura em Celcius: " << s1.getTemperaturaC() <<endl;
    cout << "Temperatura em Fahrenheit : " << s1.getTemperaturaF() <<endl;
    cout << "Temperatura em Kelvin: " << s1.getTemperaturaK() <<endl;
    //estado do umidificador e configuracao do desumidificador para definir a umidade
    cout << "Desumidificador: " << s1.getConfiguracaoDesumidificador() <<endl;
    cout << "Umidificador: " << s1.getConfiguracaoUmidificador() <<endl;
    cout << "Umidade: " << s1.getUmidade() <<endl;
    //estado do brilho da lampada e sensor se está claro
    cout << "Lampada: " << s1.getLampada() << endl;
    cout << "Brilho: " << s1.getBrilho() << endl;
}