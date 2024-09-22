#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Desumidificador: public Atuador{
    private:
        bool configuracao;

    public:
        Desumidificador(string nome, bool ligado, bool conectado, int valor, float conta, bool configuracao):Atuador(nome, ligado, conectado, valor, conta), configuracao{configuracao}{}

        void setDesumidificador(bool configuracao){
            this->configuracao = configuracao;
        }

        bool getDesumidificador(){
            return configuracao;
        }

};