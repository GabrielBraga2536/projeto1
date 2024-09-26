#pragma once
#include <iostream>
#include "Componente.hpp"
using namespace std;

class Sensor: public Componente{
    private:
        int numero;

    public:
        //Criando o construtor do "Sensor" para conectar todos sensores em um arquivo, passar todos para "Sala" e herdar de "Componentes", também cria suas funções para poder alterar valores de "numero"
        Sensor(string nome, bool ligado, bool conectado, int valor, int numero): Componente(nome, ligado, conectado, valor), numero{numero}{}

    void setNumero(int numero){
        this->numero = numero;
    }

    int getNumero(){
        return numero;
    }
};