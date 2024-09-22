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
            if (conectado == 0){
                ligado = 0;
                valor = 0;
            }
        }

        void setLigarOuDesligar(bool ligado){
            try{
                if(conectado == 0){
                    throw Defeitos("O aparelho está desconectado!");
                }
                this->ligado = ligado;
            }catch(Defeitos e){
                cout << e.mensagem << endl;
                ligado = 0;
            }
        }

        void setValorNovo(int valor){
            try{
                if(ligado == 0){
                    throw Defeitos("O aparelho está desligado!");
                }
                this->valor = valor;
            }catch(Defeitos e){
                cout << e.mensagem << endl;
                valor = 0;
            }
        }

        bool getConectadoOuDesconectado(){
            return conectado;
        }

        bool getLigadoOuDesligado(){
            return ligado;
        }

        string getNomeAtuador(){
            return nome;
        }

        int getValorAtuador(){
            return valor;
        }

};