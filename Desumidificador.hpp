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
            if (getValorAtuador() >= 0){
                configuracao = 1;
            }
            else{
                configuracao = 0;
            }
        }

        string getDesumidificador(){
            if(getValorAtuador() == 1){
                return "Ligado";
                configuracao = 1;
            }
            else{
                return "Desligado";
            }
        }

};