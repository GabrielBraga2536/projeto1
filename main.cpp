#include <iostream>
#include "Sala.hpp"
//#include "Componente.hpp"
#include "Atuador.hpp"
#include "Lampada.hpp"
#include "Desumidificador.hpp"
#include "Umidificador.hpp"
#include "Ventilador.hpp"
using namespace std;

int main(){
//    Sala s1(float temperaturaEmC, float luminosidade, float umidade, int velocidade, bool configuracao, int brilho);

//    Sala s1(float 123, float 1, float 32, int 2, bool 1, int 2);

    Sala s1(true, true, false);
    cout << "Lampada: " << s1.getBrilhoLampada() << endl;
    cout << "Desumidificador: " << s1.getConfiguracaoDesumidificador() <<endl;
    cout << "Ventilador: " << s1.getVelocidadeVentilador() <<endl;

//    s1.setVentiladorVelocidade(100);

//    cout << "Ventilador: " << s1.getVelocidadeVentilador() <<endl;

//    s1.atualizarVentilador();
//    s1.atualizarLampada();
//    s1.atualizarDesumidificador();
//    s1.atualizarUmidificador();
}