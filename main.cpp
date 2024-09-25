#include "Atuador.hpp"
#include "Componente.hpp"
#include "Desumidificador.hpp"
#include "Lampada.hpp"
#include "Luminosidade.hpp"
#include "Sala.hpp"
#include "Umidificador.hpp"
#include "Ventilador.hpp"
#include <unistd.h> //Para "sleep"
#include <cstdlib> //Para número aleatório
#include <ctime> //Para número aleatório
#include <iostream>
using namespace std;

int main() {

    // colocar seed para time(0)
    srand(time(0));

    // gera número aleatório
    int random = rand();

    //    Sala s1(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, bool brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade, float temperatura);

    Sala s1("Oi", 1, 1, 1, 1, random, 1, 1, 1, 1, 1, 1, 10, 1, 12);
    random = rand();
    Sala s2("Oii", 1, 1, 1, 1, random, 1, 1, 1, 1, 1, 1, 10, 1, 1);
    random = rand();
    Sala s3("Oi", 1, 1, 1, 1, random, 1, 1, 1, 1, 1, 1, 10, 1, 1);

    Sala *sala[3];
    sala[0] = &s1;
    sala[1] = &s2;
    sala[2] = &s3;

    for(int i = 0; i < 5 ; i++){
        sala[0]->atualizarSensores();
    sleep(1);
        sala[0]->setValorAleatorioDoAtuador(rand());
    }

    sala[0]->setNomeDoAtuador("Ventilador");
    sala[0]->setConectarOuDesconectarAtuador(0);
    sala[0]->setNomeDoAtuador("Desumidificador");
    sala[0]->setConectarOuDesconectarAtuador(0);

    for(int i = 0; i < 60 ; i++){
        sala[0]->atualizarSensores();
    sleep(1);
        sala[0]->setValorAleatorioDoAtuador(rand());
    }

    
    //sala[0]->atualizarSensores();

    // Fazendo testes das funções de "Sala"
    // sala[0]->atualizarSensores();
    // sala[0]->atualizarAtuadores();
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << "Mudando Lampada" << endl;
    // sala[0]->setNomeDoAtuador("asd");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(1);
    // cout << "Mudando Umidificador" << endl;
    // sala[0]->setNomeDoAtuador("Umidificador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(0);
    // sala[0]->setValorNovoDoAtuador(1);
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setConectarOuDesconectarAtuador(1);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(10);
    // cout << "Mudando Desumidificador" << endl;
    // sala[0]->setNomeDoAtuador("Desumidificador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(10);
    // cout << "Mudando Ventilador" << endl;
    // sala[0]->setNomeDoAtuador("Ventilador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(0);
    // sala[0]->setValorNovoDoAtuador(0);
    // cout << endl;
    // cout << endl;
    // sala[0]->atualizarSensores();
    // sala[0]->atualizarAtuadores();
}