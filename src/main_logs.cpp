#include "Atuador.hpp"
#include "Componente.hpp"
#include "Desumidificador.hpp"
#include "Lampada.hpp"
#include "Luminosidade.hpp"
#include "Sala.hpp"
#include "Umidificador.hpp"
#include "Ventilador.hpp"

#include "functions.cpp"

#include <unistd.h> //Para "sleep"
#include <cstdlib> //Para número aleatório
#include <ctime> //Para número aleatório    
#include <iostream>

using namespace std;

int main(){
  // colocar seed para time(0)
  srand(time(0));
  
  // gera número aleatório
  int random = rand();
  
  
  // Criando os objetos
  Sala s0("Oi", 1, 1, 1, 1, random, 0, 1, 1, 1, 0, 0, 55, 1, 35);
  random = rand();
  Sala s1("Oi", 1, 1, 1, 1, random, 0, 2, 1, 1, 0, 0, 40, 1, 25);
  random = rand();
  Sala s2("Oi", 1, 1, 1, 1, random, 0, 0, 1, 1, 0, 0, 80, 1, 29);
  
  // Colocando ponteiros para os objetos
  Sala *sala[3];
  sala[0] = &s0;
  sala[1] = &s1;
  sala[2] = &s2;
  
  for(int i = 1; i <= 1440; i++){
    
    cout << "Log " << i << endl << endl;
    
    cout << "Sala 1" << endl;
    sala[0]->atualizarSensores(rand());
    
    cout << "Sala 2" << endl;
    sala[1]->atualizarSensores(rand());
    
    cout << "Sala 3" << endl;
    sala[2]->atualizarSensores(rand());
    
    if(i == 200){
      sala[0]->setNomeDoAtuador("Ventilador");
      sala[0]->setConectarOuDesconectarAtuador(1);
      sala[0]->setLigarOuDesligarAtuador(1);
      sala[0]->setValorNovoDoAtuador(2);
    }
  }
  
  //Fazendo testes das funções de "Sala"
  
  // sala[0]->atualizarSensores(rand());
  // sala[0]->atualizarAtuadores();
  // cout << endl;
  // cout << endl;
  // cout << "Mudando Lampada" << endl;
  // sala[1]->setNomeDoAtuador("asd");
  // sala[1]->setConectarOuDesconectarAtuador(0);
  // sala[1]->setLigarOuDesligarAtuador(1);
  // sala[1]->setValorNovoDoAtuador(1);
  // cout << "Mudando Umidificador" << endl;
  // sala[1]->setNomeDoAtuador("Umidificador");
  // sala[1]->setConectarOuDesconectarAtuador(0);
  // sala[1]->setLigarOuDesligarAtuador(0);
  // sala[1]->setValorNovoDoAtuador(1);
  // sala[1]->setConectarOuDesconectarAtuador(0);
  // sala[1]->setConectarOuDesconectarAtuador(1);
  // sala[1]->setLigarOuDesligarAtuador(1);
  // sala[1]->setValorNovoDoAtuador(1);
  // cout << "Mudando Desumidificador" << endl;
  // sala[1]->setNomeDoAtuador("Desumidificador");
  // sala[1]->setConectarOuDesconectarAtuador(0);
  // sala[1]->setLigarOuDesligarAtuador(1);
  // sala[1]->setValorNovoDoAtuador(1);
  // cout << "Mudando Ventilador" << endl;
  // sala[1]->setNomeDoAtuador("Ventilador");
  // sala[1]->setConectarOuDesconectarAtuador(0);
  // sala[1]->setLigarOuDesligarAtuador(0);
  // sala[1]->setValorNovoDoAtuador(0);
  // cout << endl;
  // cout << endl;
  // sala[1]->atualizarSensores(rand());
  // sala[1]->atualizarAtuadores();
  
  return 0;
}