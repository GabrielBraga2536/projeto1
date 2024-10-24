/*
* RESUMO DO CÓDIGO: 
Os atuadores (Lampada, Umidificador, Desumidificador e Ventilador)
Os atuadores podem ser conectados ou desconectados (um aparelho desligado não pode ser ligado nem receber um valor) (vai precisar ligar novamente e colocar novamente um valor para ele começar a atuar)
Os atuadores podem ser ligados ou desligaods (um aparelho desligado não pode receber um valor) (vai precisar colocar novamente um valor para ele começar a atuar)

A Lampada está ligada com o sensor de luminosidade
A Umidificador está ligada com o sensor de umidade
O Desumidificador está ligado com o sensor de umidade
O Ventilador está ligado com o sensor de temperatura

A intensidade define se a lampada começa desconectada ou conectada (mas o brilho também deve estar com um valor de acordo para não gerar problemas)
O brilho (int) está relacionado com a Lampada possui os valores de 0, 1 e 2, a luminosidade apresenta um valor manor que 10 se o brilho = 0, um valor menor que 500 se o brilho = 1 e um valor menor que 1000 se brilho = 2

A configuracao (bool) está relacionada com o Desumidificador (se o valor for igual a 1 ele está ligado e se 0 está desligado), se o desumidificador estiver ligado a umidade desce até 40%
O estado (bool) está relacionado com o Umidificador (se o valor for igual a 1 ele está ligado e se 0 está desligado), se o umidificador estiver ligado a umidade sobe até 60%
Se o Umidificador e o Desumidificador tiverem o mesmo estado o umidade não altera
A umidadeRelativa (float) coloca o valor inicial da umidade

O ajuste (bool) define se o ventilador começa desconectado ou conectado (mas a velocidade também deve estar com um valor de acordo para não gerar problemas)
A velocidade (int) está relacionada o Ventilador, se velocidade = 1/2/3 o temperatura (float) desce até 10ºC (desce mais um pouco pela flutuação) quanto maior a velocidade mais rápido a temperatura desce, se velocidade = 0 a temperatura sobe até 35ºC (sobe mais um pouco pela flutuação)
A temperatura coloca o valor inicial da temperatura

Os outros valores do construtor da sala (nome, ligado, conectado, valor, conta, numero) são utilizados nas funções e seus valores iniciais não afetam o código

A função "setNomeDoAtuador" deve ser colocado uma string com o nome do atuador que será alterado
A função "setConectarOuDesconectarAtuador" deve ser colocado um bool com o valor que será alterado
A função "setLigarOuDesligarAtuador" deve ser colocado um bool com o valor que será alterado
A função "setValorNovoDoAtuador" deve ser colocado um valor inteiro para alterar o valor do atuador
A função "atualizarSensores" imprime os valores dos sensores e precisa do "rand()" para fazer a flutuação dos sensores
A função "atualizarAtuadores" imprime o estado de todos atuadores

Se necessário colocar sleep para reduzir a agilidade do cógido, o número é em segundos   

* CONSTRUTOR DA SALA:
Sala(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, int brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade, float temperatura):
*/

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


int main() {
  
  // colocar seed para time(0)
  srand(time(0));
  
  // gera número aleatório
  int random = rand();
  int valor;
  
  int escolherSala = 0, aletandoAtuador = 0, decisaoSala = 0;
  string atuadorEscolhido;
  
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
  
  while(true){
    menuPrincipal();
    cin >> escolherSala;
    
    if (escolherSala == 4){break;}
    else if (escolherSala <= 0 || escolherSala >= 5){}
    else{
      while(true){
        menuSala1(escolherSala, sala[escolherSala - 1]);
        sala[escolherSala - 1]->atualizarSensores(rand());
        menuSala(escolherSala, sala[escolherSala - 1]);
        cin >> decisaoSala;
        if (decisaoSala == 2){break;}
        else if (decisaoSala <= 0 || decisaoSala >= 4 || decisaoSala == 3){}
        else{
          while(true){
            menuAtuadoresLetras(escolherSala, sala[escolherSala - 1], escolherSala); 
            sala[escolherSala - 1]->atualizarAtuadores();
            atuadorEscolhido = menuAtuadores(escolherSala, sala[escolherSala - 1], escolherSala);
            if (atuadorEscolhido == "Sair"){break;}
            else if (escolherSala <= 0 || escolherSala >= 6){}
            else{
              sala[escolherSala - 1]->setNomeDoAtuador(atuadorEscolhido);
              aletandoAtuador = alterarAtuador();
                if(aletandoAtuador == 1){
              sala[escolherSala - 1]->setConectarOuDesconectarAtuador(1);
                }   
                else if(aletandoAtuador == 2){
                  sala[escolherSala - 1]->setConectarOuDesconectarAtuador(0);
                }  
                else if(aletandoAtuador == 3){
                  sala[escolherSala - 1]->setLigarOuDesligarAtuador(1);
                }  
                else if(aletandoAtuador == 4){
                  sala[escolherSala - 1]->setLigarOuDesligarAtuador(0);
                } 
                else if(aletandoAtuador == 5){
                  cout << endl << "Para qual valor? ";
                  cin >> valor;
                  sala[escolherSala - 1]->setValorNovoDoAtuador(valor);
                }  
                else {}
            
            sleep(1);
            
            if (aletandoAtuador == 6){break;}
            }
          }
        }
      }
    }
  }
  
  return 0;
}