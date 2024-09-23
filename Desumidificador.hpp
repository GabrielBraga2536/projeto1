#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Desumidificador: public Atuador{
    private:
        bool configuracao;

    public:
        //Construtor do "Desumidificador", indicando se esse atuador está ligado ou desligado, conectado ou desconectado e o valor atual desse atuador
        Desumidificador(string nome, bool ligado, bool conectado, int valor, float conta, bool configuracao):Atuador(nome, ligado, conectado, valor, conta), configuracao{configuracao}{}

        //Função para alterar o estado de ligado ou desligado do Desumidificador (não está sendo utilizador, provável que será alterado, pois isso é alterado pelos valores de "ligado", "conectado" e "valor")
        void setDesumidificador(bool configuracao){
            if (getValorAtuador() >= 0){
                configuracao = 1;
            }
            else{
                configuracao = 0;
            }
        }
        //Função para informar o estado do Desumidificador
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