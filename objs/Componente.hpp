#pragma once
#include <iostream>
#include "Defeitos.hpp"
using namespace std;

class Componente{
    private:
        bool ligado;
        bool conectado;
        int valor;
        string nome;

    public:
        //criando o construtor de "Componente" e suas funções para alterar os valores de ligado, conectado e valor
        Componente(string nome, bool ligado, bool conectado, int valor){
            this->ligado = ligado;
            this->conectado = conectado;
            this->valor = valor;
            this->nome = nome;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setConectarOuDesconectar(bool conectado){
            this->conectado = conectado;
        }

        void setLigarOuDesligar(bool ligado){
            this->ligado = ligado;
        }

        void setValorNovo(int valor){
            this->valor = valor;
        }

        bool getConectadoOuDesconectado(){
            return conectado;
        }

        bool getLigadoOuDesligado(){
            return ligado;
        }

        string getEstadoDesconectado(){
            if (conectado == 1){
                return "Conectado";
            }
            else{
                return "Desconectado";
            }
        }

        string getEstadoLigado(){
            if (ligado == 1){
                return "Ligado";
            }
            else{
                return "Desligado";
            }
        }

        string getNomeAtuador(){
            return nome;
        }

        int getValorAtuador(){
            return valor;
        }
};