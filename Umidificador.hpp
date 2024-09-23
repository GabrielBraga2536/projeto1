#pragma once
#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador: public Atuador{
    private:
        bool estado;
        bool ajuste;

    public:
        //Construtor do "Umidificador", indicando se esse atuador está ligado ou desligado, conectado ou desconectado e o valor atual desse atuador
        Umidificador(string nome, bool ligado, bool conectado, int valor, float conta, bool estado, bool ajuste):Atuador(nome, ligado, conectado, valor, conta), estado{estado}, ajuste{ajuste}{}
        //Função para alterar se o Umidificador está ligado ou desligado(provavelmente será removido, pois isso é alterado pelos valores de "ligado", "conectado" e "valor")
        void setUmidificador(bool estado){
            ajuste = 0;
            this->estado = estado;
        }
        //Função para informar se o Umidificador está ligado ou desligado
        string getUmidificador(){
            if(getValorAtuador() == 1){
                return "Ligado";
            }
            else{
                return "Desligado";
            }
        }

};