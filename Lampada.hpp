#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Lampada: public Atuador{
    private:
        bool brilho;
        int intensidade;

    public:
        Lampada(string nome, bool ligado, bool conectado, int valor, float conta, bool brilho, int intensidade):Atuador(nome, ligado, conectado, valor, conta), brilho{brilho}, intensidade{intensidade}{}

        void setBrilho(bool brilho){
            intensidade = 0;
            this->brilho = brilho;
        }

        bool getLampadaEstado(){
            return brilho;
        } 

};