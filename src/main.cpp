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
    
    int escolhaPrincipal = 0;
    int escolhaSala = 0;
    
    // Criando os objetos
    Sala s0("Oi", 1, 1, 1, 1, random, 2, 2, 1, 1, 0, 1, 55, 1, 35);
    random = rand();
    Sala s1("Oi", 1, 1, 1, 1, random, 1, 1, 1, 1, 1, true, 50, 1, 1);
    random = rand();
    Sala s2("Oi", 1, 1, 1, 1, random, 1, 1, 1, 1, 1, 1, 10, 1, 1);
    
    // Colocando ponteiros para os objetos
    Sala *sala[3];
    sala[0] = &s0;
    sala[1] = &s1;
    sala[2] = &s2;
    
    while(true){
        switch (escolhaPrincipal){
        case 0:
            menuPrincipal();
            cin >> escolhaPrincipal;
            break;
        case 1:
            menuSala(1, sala[0]);
            break;
        case 2:
            menuSala(2, sala[1]);
            break;
        case 3:
            menuSala(3, sala[2]);
            break;
        default:
            break;
        }
        if(escolhaSala == 4){
            break;
        }
        do{
            switch (escolhaSala){
            case 1:
                
                break;
            case 2:
                break;
            default:
                break;
            }
        }while(escolhaSala != 2);


    }
    

    /* CONSTRUTOR DA SALA:
    Sala(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, int brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade, float temperatura) : 

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

     Se necessário colocar sleep para reduzir a agilidade do cógido, o número é em segundos */


    // Usando as funções
    
    // for(int i = 0; i < 1 ; i++){
    //     sala[0]->atualizarSensores(rand());
    //     sleep(1);
    // }

    // sala[0]->setNomeDoAtuador("Desumidificador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setNomeDoAtuador("Ventilador");
    // sala[0]->setConectarOuDesconectarAtuador(1);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(1);
    // sala[0]->setNomeDoAtuador("Lampada");
    // sala[0]->setConectarOuDesconectarAtuador(1);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(2);
    // sleep(1);

    // for(int i = 0; i < 1440; i++){
    //     sala[0]->atualizarSensores(rand());
    //     sleep(1);
    // }

    //Fazendo testes das funções de "Sala"
    
    // sala[0]->atualizarSensores(rand());
    // sala[0]->atualizarAtuadores();
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
    // sala[0]->setValorNovoDoAtuador(1);
    // cout << "Mudando Desumidificador" << endl;
    // sala[0]->setNomeDoAtuador("Desumidificador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(1);
    // sala[0]->setValorNovoDoAtuador(1);
    // cout << "Mudando Ventilador" << endl;
    // sala[0]->setNomeDoAtuador("Ventilador");
    // sala[0]->setConectarOuDesconectarAtuador(0);
    // sala[0]->setLigarOuDesligarAtuador(0);
    // sala[0]->setValorNovoDoAtuador(0);
    // cout << endl;
    // cout << endl;
    // sala[0]->atualizarSensores(rand());
    // sala[0]->atualizarAtuadores();
}