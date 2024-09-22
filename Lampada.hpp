#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Lampada: public Atuador{
    private:
        int brilho;
        int intensidade;

    public:
        Lampada(string nome, bool ligado, bool conectado, int valor, float conta, int brilho, int intensidade):Atuador(nome, ligado, conectado, valor, conta), brilho{brilho}, intensidade{intensidade}{}

        void setBrilho(){
            if (getValorAtuador() >= 1){
                brilho = 1;
            }
            else{
                brilho = 0;
            }
            intensidade = getValorAtuador();
        }

        int getLampadaEstado(){
            return getValorAtuador();
        } 

};