#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Lampada: public Atuador{
    private:
        int brilho;
        bool intensidade;

    public:
        //Construtor da "Lampada", indicando se esse atuador está ligado ou desligado, conectado ou desconectado e o valor atual desse atuador
        Lampada(string nome, bool ligado, bool conectado, int valor, float conta, int brilho, bool intensidade):Atuador(nome, ligado, conectado, valor, conta), brilho{brilho}, intensidade{intensidade}{}
        //Função para alterar o valor do "brilho" da Lampada, não está sendo utilizada e provavelmente será alterado
        void setBrilho(int brilho){
            this->brilho = brilho;
            intensidade = 1;
        }
        //Função para informar o valor  da Lampada
        int getLampadaEstado(){
            return getValorAtuador();
        } 

};