# Projeto 1

Primeiro projeto da disciplina de Orientação a Objetos (CCP-140) do Curso de Engenharia de Robôs da FEI.

O projeto consiste em um sistema de controle de ambientes que controla diferentes tipos de atuadores e sensores. O sistema é capaz de atualizar os sensores e atuadores com base em suas funcionalidades específicas.

O arquivo main_sys.cpp se refere sistema de controle operado por um usuário. Já o "main_logs.cpp" se refere ao sistema automático que roda 1440 simulações. 

Atuadores:
  -Ventilador
  -Umidificador
  -Desumidificador
  -Lâmpada

Sensores:
  -Temperatura
  -Luminosidade
  -Umidade

## Índice

- [Ferramentas](#ferramentas-utilizadas)
- [Instalação](#instalação)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Comandos](#comandos)
- [Repositório](#clonar-o-repositório)

## Ferramentas utilizadas

- [Linguagem] C++
- [Compilador] MinGW
- [IDE] Visual Studio Code

## Instalação

Para instalar o compilador: https://sourceforge.net/projects/mingw/files/

Para instalar a IDE: https://code.visualstudio.com/download

## Estrutura do projeto

1. Sala (Classe)
  
  Atributos:
    Atuador[] atuadores
    Sensor[] sensores
  
  Métodos:
    +void atualizarSensores()
    +void atualizarAtuadores()

2. Componente (Classe)
  
  Atributos:
    bool ligado
    bool conectado
    int valor
    string nome
  
  Métodos:
    +void ligar()
    +void desligar()
    +bool conectar()
    +void desconectar()
    +int getValor()

3. Sensor (Classe) (Herança de Componente)
  
  Subclasses de Sensor:
    
    Temperatura
      Métodos:    
        +float getTemperaturaEmC()
        +float getTemperaturaEmF()
        +float getTemperaturaEmK()
    
    Luminosidade
      Atributos:
        int limiarClaridade
      
      Métodos:
        +void setLimiarClaridade(int)
        +bool estaClaro()
    
    Umidade
      Métodos:
      +float getUmidadeRelativa()

4. Atuador (Classe) (Herança de Componente)
  
  Métodos:
    +bool setValor(int)
  
  Subclasses de Atuador:
    
    Ventilador  
      Métodos:
        +bool setVelocidade(int)
    
    Umidificador
      Métodos:
        +bool setConfiguracao(int)
    
    Desumidificador
      Métodos:
        +bool setConfiguracao(int)
    
    Lâmpada
      Métodos:
        +bool setBrilho(int)

Obs: para uma melhor visualização da estrutura do projeto, verifique o arquivo "diagrama_de_classes.png" na pasta refs.

## Comandos

Para compilar o projeto:
g++ -I \Caminho\até\a\pasta\projeto1\objs -I \Caminho\até\a\pasta\projeto1\refs -o a.exe main_sys.cpp

Para entrar no diretório da main:
cd src

Para rodar o projeto:
.\a.exe

## Clonar o repositório
git clone https://github.com/GabrielBraga2536/projeto1


