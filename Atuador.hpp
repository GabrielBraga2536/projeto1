#pragma once 
#include <iostream>
#include "Componente.hpp"
using namespace std;

class Atuador: public Componente{
    private:
        float conta;
    public:
        //Criando o construtor do "Atuador" para conectar todos atuadores em um arquivo, passar todos para "Sala" e herdar de "Componentes", também cria suas funções para poder alterar valores de "conta"
        Atuador(string nome, bool ligado, bool conectado, int valor, float conta): Componente(nome, ligado, conectado, valor), conta{conta}{}

        int getValor() { 
            return conta; 
        } 
        bool setValor(int conta) { 
            return conta; 
        } 
};