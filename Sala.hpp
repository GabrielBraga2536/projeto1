#pragma once
#include <iostream>
#include "Atuador.hpp"
#include "Ventilador.hpp"
#include "Umidificador.hpp"
#include "Desumidificador.hpp"
#include "Lampada.hpp"
#include "Luminosidade.hpp"
#include "Umidade.hpp"
#include "Temperatura.hpp"
#include "Sensor.hpp"
using namespace std;

class Sala{
    private:
        Ventilador ventilador;
        Desumidificador desumidificador;
        Umidificador umidificador;
        Lampada lampada;
        Luminosidade luminosidade;
        Temperatura temperatura;
        Umidade umidade;
        Atuador atuador;

    public:

        Sala(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, int brilho, int intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade) : 
            ventilador{nome, ligado, conectado, valor, conta, velocidade}, 
            desumidificador{nome, ligado, conectado, valor, conta, configuracao}, 
            umidificador{nome, ligado, conectado, valor, conta, estado, ajuste}, 
            lampada{nome, ligado, conectado, valor, conta, brilho, intensidade}, 
            luminosidade{nome, ligado, conectado, valor, numero, brilho, luminosidade}, 
            temperatura{nome, ligado, conectado, valor, numero, velocidade}, 
            umidade{nome, ligado, conectado, valor, numero, umidadeRelativa, configuracao, estado}, 
            atuador{nome, ligado, conectado, valor, conta}{}

        void atualizarAtuadores(){
            cout << "Velocidade do ventilador: " << ventilador.getVelocidade() << endl;
            cout << "Intensidade da lampada: " << lampada.getLampadaEstado() << endl;
            cout << "Configuração do desumidificador: " << desumidificador.getDesumidificador() << endl;
            cout << "Configuração do umidificador: " << umidificador.getUmidificador() << endl;
        }

        void atualizarSensores(){
            cout << "Sensor de temperatura em Celcius: " << temperatura.getTemperaturaEmC() << endl;
            cout << "Sensor de temperatura em Fahrenheit: " << temperatura.getTemperaturaEmF() << endl;
            cout << "Sensor de temperatura em Kelvin: " << temperatura.getTemperaturaEmK() << endl;
            cout << "Sensor de luminosidade: " << luminosidade.estaClaro() << endl;
            cout << "Sensor de umidade relativa: " << umidade.getUmidadeRelativa() << endl;
        }

        void setNomeDoAtuador(string nome){
            atuador.setNome(nome);
            try{
                if (atuador.getNomeAtuador() == "Lampada"){
                    atuador.setConectarOuDesconectar(lampada.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(lampada.getLigadoOuDesligado());
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    atuador.setConectarOuDesconectar(desumidificador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(desumidificador.getLigadoOuDesligado());
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    atuador.setConectarOuDesconectar(umidificador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(umidificador.getLigadoOuDesligado());
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    atuador.setConectarOuDesconectar(ventilador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(ventilador.getLigadoOuDesligado());
                }
                else{
                    throw Defeitos("O nome do Atuador é inválido");
                }
            }catch(Defeitos e){
                cout << e.mensagem << endl;
            }
        }

        void setLigarOuDesligarAtuador(bool ligado){
            try{
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setLigarOuDesligar(ligado);
                    luminosidade.setLigarOuDesligar(ligado);
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setLigarOuDesligar(ligado);
                    umidade.setLigarOuDesligar(ligado);
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setLigarOuDesligar(ligado);
                    umidade.setLigarOuDesligar(ligado);
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setLigarOuDesligar(ligado);
                    temperatura.setLigarOuDesligar(ligado);
                }
                else{
                    throw Defeitos("O nome do Atuador é inválido");
                }
            }catch(Defeitos e){
                cout << e.mensagem << endl;
            }
        }

        void setConectarOuDesconectarAtuador(bool conectado){
            try{
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setConectarOuDesconectar(conectado);
                    luminosidade.setConectarOuDesconectar(conectado);
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setConectarOuDesconectar(conectado);
                    umidade.setConectarOuDesconectar(conectado);
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setConectarOuDesconectar(conectado);
                    umidade.setConectarOuDesconectar(conectado);
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setConectarOuDesconectar(conectado);
                    temperatura.setConectarOuDesconectar(conectado);
                }
                else{
                    throw Defeitos("O nome do Atuador é inválido");
                }
            }catch(Defeitos e){
                cout << e.mensagem << endl;
            }
        }

        void setValorNovoDoAtuador(int valor){
            try{
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setValorNovo(valor);
                    luminosidade.setValorNovo(valor);
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setValorNovo(valor);
                    umidade.setValorNovo(valor);
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setValorNovo(valor);
                    umidade.setValorNovo(valor);
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setValorNovo(valor);
                    temperatura.setValorNovo(valor);
                }
                else{
                    throw Defeitos("O nome do Atuador é inválido");
                }
            }catch(Defeitos e){
                cout << e.mensagem << endl;
            }
        }
};