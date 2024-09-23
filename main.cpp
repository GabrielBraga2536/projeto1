#include <iostream>
#include "Sala.hpp"
#include "Componente.hpp"
#include "Atuador.hpp"
#include "Lampada.hpp"
#include "Desumidificador.hpp"
#include "Umidificador.hpp"
#include "Ventilador.hpp"
#include "Luminosidade.hpp"
using namespace std;

int main(){
//    Sala s1(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, bool brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade);

    Sala s1("Oi",1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1);

    //Fazendo testes das funções de "Sala"
    s1.atualizarSensores();
    s1.atualizarAtuadores();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Mudando Lampada" << endl;
    s1.setNomeDoAtuador("asd");
    s1.setConectarOuDesconectarAtuador(0);
    s1.setLigarOuDesligarAtuador(1);
    s1.setValorNovoDoAtuador(1);
    cout << "Mudando Umidificador" << endl;
    s1.setNomeDoAtuador("Umidificador");
    s1.setConectarOuDesconectarAtuador(0);
    s1.setLigarOuDesligarAtuador(0);
    s1.setValorNovoDoAtuador(1);
    s1.setConectarOuDesconectarAtuador(0);
    s1.setConectarOuDesconectarAtuador(1);
    s1.setLigarOuDesligarAtuador(1);
    s1.setValorNovoDoAtuador(10);
    cout << "Mudando Desumidificador" << endl;
    s1.setNomeDoAtuador("Desumidificador");
    s1.setConectarOuDesconectarAtuador(0);
    s1.setLigarOuDesligarAtuador(1);
    s1.setValorNovoDoAtuador(10);
    cout << "Mudando Ventilador" << endl;
    s1.setNomeDoAtuador("Ventilador");
    s1.setConectarOuDesconectarAtuador(0);
    s1.setLigarOuDesligarAtuador(0);
    s1.setValorNovoDoAtuador(0);
    cout << endl;
    cout << endl;
    s1.atualizarSensores();
    s1.atualizarAtuadores();

}