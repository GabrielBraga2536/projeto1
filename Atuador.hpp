#pragma once 
#include <iostream>
#include "Componente.hpp"
using namespace std;

class Atuador: public Componente{
    private:
        float conta;
    public:
        Atuador(string nome, bool ligado, bool conectado, int valor, float conta): Componente(nome, ligado, conectado, valor), conta{conta}{}

        int getValor() { 
            return conta; 
        } 
        bool setValor(int conta) { 
            return conta; 
        } 
};