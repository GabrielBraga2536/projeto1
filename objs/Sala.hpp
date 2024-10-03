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
        Sensor sensor;
        //O atuador "Lampada" está conectado com o sensor de "Luminosidade", o "Umidificador" e "Desumidificador" com o sensor de "Umidade", o "Ventilador" com o sensor de "Temperatura"
    public:
        //Definindo o construtor de "Sala" 
        //nome -> informa o nome do atuador que será alterado;
        //ligado -> informa se esse atuador está ligado ou desligado (um atuador desligado tem seu valor alterado para 0)
        // conectado -> informa se esse atuador está ligado ou desligado (um atuador desconectado é desligado e tem seu valor alterado para 0)
        // valor -> informa o valor da intensidade atual desse atuador
        //conta, numero, velocidade, brilho, intensidade, estado, ajuste, configuracao, umidadeRelativa, luminosidade não estão sendo usados por hora, apenas servem para criar construtores diferentes para cada classe 
        Sala(string nome, bool ligado, bool conectado, int valor, float conta, int numero, int velocidade, int brilho, bool intensidade, bool estado, bool ajuste, bool configuracao, float umidadeRelativa, float luminosidade, float temperatura) : 
            ventilador{nome, ajuste, ajuste, velocidade, conta, ajuste, velocidade}, 
            desumidificador{nome, configuracao, configuracao, configuracao, conta, configuracao}, 
            umidificador{nome, estado, estado, estado, conta, estado, ajuste}, 
            lampada{nome, intensidade, intensidade, brilho, conta, brilho, intensidade}, 
            luminosidade{nome, ligado, conectado, valor, numero, brilho, luminosidade}, 
            temperatura{nome, ligado, conectado, valor, numero, velocidade, temperatura}, 
            umidade{nome, ligado, conectado, valor, numero, umidadeRelativa, configuracao, estado, ajuste}, 
            atuador{nome, ligado, conectado, valor, conta}, 
            sensor{nome, ligado, conectado, valor, numero}{}
        //Função para imprimir se atuadores estão ligados
        void atualizarAtuadores(){
            cout << "Velocidade do ventilador: " << ventilador.getVelocidade() << endl;
            cout << "Intensidade da lampada: " << lampada.getLampadaEstado() << endl;
            cout << "Configuração do desumidificador: " << desumidificador.getDesumidificador() << endl;
            cout << "Configuração do umidificador: " << umidificador.getUmidificador() << endl;
        }
        //Função para imprimir os valores que os sensores estão detectando
        void atualizarSensores(int numero){
            luminosidade.setNovaLuminosidade();
            temperatura.setNovaTemperatura();
            umidade.setNovaUmidade();
            cout << "Sensor de temperatura em Celcius: " << temperatura.getTemperaturaEmC() << endl;
            cout << "Sensor de temperatura em Fahrenheit: " << temperatura.getTemperaturaEmF() << endl;
            cout << "Sensor de temperatura em Kelvin: " << temperatura.getTemperaturaEmK() << endl;
            cout << "Sensor de luminosidade: " << luminosidade.estaClaro() << endl;
            cout << "Sensor de umidade relativa: " << umidade.getUmidadeRelativa() << "%" << endl << endl;
            umidade.setNumero(numero);
            luminosidade.setNumero(numero);
            temperatura.setNumero(numero); 
        }
        //Função para alterar o atuador que está sendo mexido
        void setNomeDoAtuador(string nome){
            atuador.setNome(nome);
            try{
                //Garante que os valores "conectado, ligado e valor" sejam os mesmo entre o atuador que está sendo mexido e a classe "Atuado", cada caso é para procurar qual atuador está sendo mexido 
                if (atuador.getNomeAtuador() == "Lampada"){
                    atuador.setConectarOuDesconectar(lampada.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(lampada.getLigadoOuDesligado());
                    atuador.setValorNovo(lampada.getValorAtuador());
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    atuador.setConectarOuDesconectar(desumidificador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(desumidificador.getLigadoOuDesligado());
                    atuador.setValorNovo(desumidificador.getValorAtuador());
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    atuador.setConectarOuDesconectar(umidificador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(umidificador.getLigadoOuDesligado());
                    atuador.setValorNovo(umidificador.getValorAtuador());
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    atuador.setConectarOuDesconectar(ventilador.getConectadoOuDesconectado());
                    atuador.setLigarOuDesligar(ventilador.getLigadoOuDesligado());
                    atuador.setValorNovo(ventilador.getValorAtuador());
                }
                //Informa que o nome do atuador não foi encontrado
                else{
                    throw Defeitos("O nome desse atuador é inválido ");
                }
                //Informa o nome do atuador que foi definido
                cout << "O nome " << atuador.getNomeAtuador() << " foi definido." << endl;

            }catch(Defeitos e){
                    cout << e.mensagem << " (" << atuador.getNomeAtuador() << ")" << endl;
                }
        }
        //Função para alterar o estado de ligado e desligado do atuador sendo mexido
        void setLigarOuDesligarAtuador(bool ligado){
            try{
                //Verifica se o atuador está conectado, se não estiver informa isso para o usuário, também verifica se o nome do atuador é válido, se não for, essa função é parada e informa isso para o usuário (qual é o nome do atuador inválido)
                if (atuador.getNomeAtuador() == "Lampada" || atuador.getNomeAtuador() == "Desumidificador" || atuador.getNomeAtuador() == "Umidificador" || atuador.getNomeAtuador() == "Ventilador"){
                    if(atuador.getConectadoOuDesconectado() == 0){
                        throw Defeitos("O atuador está desconectado!");
                    }
                }
                else{
                    throw Defeitos("O nome desse atuador é inválido ");
                }

                //Verifica se o atuador já estava no estado pedido
                if (ligado == atuador.getLigadoOuDesligado()){
                    if (ligado == 1){
                        throw Defeitos("O atuador já está ligado");
                    }
                    else{
                        throw Defeitos("O atuador já está desligado");
                    }
                }

                atuador.setLigarOuDesligar(ligado);
                
                //Função para ligar ou desligar o atuador, e informa isso para o sensor correspondente (cada caso é para um atuador)
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setLigarOuDesligar(ligado);
                    luminosidade.setLigarOuDesligar(ligado);
                    //Se o atuador for desligado altera o valor dele para 0 também
                    if(ligado == 0){
                        lampada.setBrilho(0);
                        luminosidade.setBrilhoNovo(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setLigarOuDesligar(ligado);
                    umidade.setConfiguracaoDesumidificador(ligado);
                    if(ligado == 0){
                        desumidificador.setDesumidificador(0);
                        umidade.setConfiguracaoDesumidificador(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setLigarOuDesligar(ligado);
                    umidade.setConfiguracaoUmidificador(ligado);
                    if(ligado == 0){
                        umidificador.setUmidificador(0);
                        umidade.setConfiguracaoUmidificador(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setLigarOuDesligar(ligado);
                    temperatura.setLigarOuDesligar(ligado);
                    if(ligado == 0){
                        ventilador.setVelocidade(0);
                        temperatura.setNovaVelocidade(0);
                        atuador.setValorNovo(0);
                    }
                }
                //Informa se o atuador foi ligado ou desligado com sucesso
                if(ligado == 1){
                    cout << atuador.getNomeAtuador() << " foi ligado." << endl;
                }
                else{
                    cout << atuador.getNomeAtuador() << " foi desligado." << endl;
                }
            //Informa se o nome do atuador é inválido
            }catch(Defeitos e){
                    cout << e.mensagem << " (" << atuador.getNomeAtuador() << ")" << endl;
                }
        }
        //Função para conectar ou desconectar o atuador sendo mexido
        void setConectarOuDesconectarAtuador(bool conectado){
            try{
                //Verifica se o atuador já estava no estado pedido
                if (atuador.getConectadoOuDesconectado() == conectado){
                    if (conectado == 1){
                        throw Defeitos("O atuador já está conectado");
                    }
                    else{
                        throw Defeitos("O atuador já está desconectado");
                    }
                }
                
                atuador.setConectarOuDesconectar(conectado);
                
                //Cada caso está procurando qual atuador está sendo mexido e informa isso para o sensor correspondente
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setConectarOuDesconectar(conectado);
                    luminosidade.setConectarOuDesconectar(conectado);
                    //Se o atuador for desconectado altera o valor dele para 0 e também o desliga, informado isso para o sensor e a classe "Atuador"
                    if(conectado == 0){
                        lampada.setLigarOuDesligar(0);
                        luminosidade.setLigarOuDesligar(0);
                        lampada.setBrilho(0);
                        luminosidade.setBrilhoNovo(0);
                        atuador.setLigarOuDesligar(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setConectarOuDesconectar(conectado);
                    umidade.setConfiguracaoDesumidificador(conectado);
                    if(conectado == 0){
                        desumidificador.setLigarOuDesligar(0);
                        umidade.setConfiguracaoDesumidificador(0);
                        desumidificador.setDesumidificador(0);
                        atuador.setLigarOuDesligar(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setConectarOuDesconectar(conectado);
                    umidade.setConfiguracaoUmidificador(conectado);
                    
                    if(conectado == 0){
                        umidificador.setLigarOuDesligar(0);
                        umidade.setConfiguracaoUmidificador(0);
                        umidificador.setUmidificador(0);
                        atuador.setLigarOuDesligar(0);
                        atuador.setValorNovo(0);
                    }
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setConectarOuDesconectar(conectado);
                    temperatura.setConectarOuDesconectar(conectado);
                    if(conectado == 0){
                        ventilador.setLigarOuDesligar(0);
                        temperatura.setLigarOuDesligar(0);
                        ventilador.setVelocidade(0);
                        temperatura.setNovaVelocidade(0);
                        atuador.setLigarOuDesligar(0);
                        atuador.setValorNovo(0);
                    }
                }
                //Informa se o nome do atuador é inválido
                else{
                    throw Defeitos("O nome desse atuador é inválido ");
                }
                //Informa para o usuário se o atuador foi conectado ou desconectado com sucesso
                if(conectado == 1){
                    cout << atuador.getNomeAtuador() << " foi conectado." << endl;
                }
                else{
                    cout << atuador.getNomeAtuador() << " foi desconectado." << endl;
                }
            }catch(Defeitos e){
                    cout << e.mensagem << " (" << atuador.getNomeAtuador() << ")" << endl;
                }
        }
        //Função para alterar o valor do atuador sendo mexido
        void setValorNovoDoAtuador(int valor){
            try{
                //Verifica se esse atuador existe, e se ele está conectado e ligado, se não estiver informa isso para o usuário
                if (atuador.getNomeAtuador() == "Lampada" || atuador.getNomeAtuador() == "Desumidificador" || atuador.getNomeAtuador() == "Umidificador" || atuador.getNomeAtuador() == "Ventilador"){
                    if(atuador.getConectadoOuDesconectado() == 0){
                        throw Defeitos("O atuador está desconetado!");
                    }
    
                    if(atuador.getLigadoOuDesligado() == 0){
                        throw Defeitos("O atuador está desligado!");
                    }
                }
                else{
                    throw Defeitos("O nome desse atuador é inválido ");
                }
                
                //Verifica se o atuador já estava no estado pedido
                if (valor == atuador.getValorAtuador()){
                    throw Defeitos("O atuador já está nesse estado");
                }

                atuador.setValorNovo(valor);
                
                //Altera o valor do atuador, informando isso para o sensor correspondente, cada caso é para um atuador diferente
                if (atuador.getNomeAtuador() == "Lampada"){
                    lampada.setBrilho(valor);
                    luminosidade.setBrilhoNovo(valor);
                }
                else if (atuador.getNomeAtuador() == "Desumidificador"){
                    desumidificador.setDesumidificador(valor);
                    umidade.setConfiguracaoDesumidificador(valor);
                }
                else if (atuador.getNomeAtuador() == "Umidificador"){
                    umidificador.setUmidificador(valor);
                    umidade.setConfiguracaoUmidificador(valor);
                }
                else if (atuador.getNomeAtuador() == "Ventilador"){
                    ventilador.setVelocidade(valor);
                    temperatura.setNovaVelocidade(valor);
                }
                //Informa que o valor do atuador foi alterado com sucesso
                cout << atuador.getNomeAtuador() << " teve seu valor alterado para " << atuador.getValorAtuador() << endl;
                
            }catch(Defeitos e){
                cout << e.mensagem << " (" << atuador.getNomeAtuador() << ")" << endl;
            }
        }

        int getValorAleatorioDoAtuador(){
            return umidade.getNumero();
            return luminosidade.getNumero();
            return temperatura.getNumero();
        }
};