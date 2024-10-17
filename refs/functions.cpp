#include <iostream>
#include <stdlib.h>
#include <unistd.h> 

#include <Sala.hpp>

using namespace std;

void menuPrincipal(){
  system("cls");
  
  cout << R"(
  ____            _             _            _      
 / ___|___  _ __ | |_ _ __ ___ | | ___    __| | ___ 
| |   / _ \| '_ \| __| '__/ _ \| |/ _ \  / _` |/ _ \
| |__| (_) | | | | |_| | | (_) | |  __/ | (_| |  __/
 \____\___/|_| |_|\__|_|  \___/|_|\___|  \__,_|\___|
    _              _     _            _             
   / \   _ __ ___ | |__ (_) ___ _ __ | |_ ___       
  / _ \ | '_ ` _ \| '_ \| |/ _ \ '_ \| __/ _ \      
 / ___ \| | | | | | |_) | |  __/ | | | ||  __/      
/_/   \_\_| |_| |_|_.__/|_|\___|_| |_|\__\___| )" << endl << endl;

  cout << " 1 - Sala 1                  3 - Sala 3" << endl;
  cout << " 2 - Sala 2                  4 - Sair" << endl << endl;
  cout << " O que deseja fazer: ";
}



void menuSala(int s, Sala sala[3]){
  system("cls");
  
  
  //Titulo da sala selecionada
  if(s == 1){
    cout << R"(                                      
 ____        _          _ 
/ ___|  __ _| | __ _   / |
\___ \ / _` | |/ _` |  | |
 ___) | (_| | | (_| |  | |
|____/ \__,_|_|\__,_|  |_| )" << endl << endl;
    
    sala[s].atualizarSensores(rand());
  }
  else if(s == 2){
    cout << R"(  
 ____        _          ____  
/ ___|  __ _| | __ _   |___ \ 
\___ \ / _` | |/ _` |    __) |
 ___) | (_| | | (_| |   / __/ 
|____/ \__,_|_|\__,_|  |_____| )" << endl << endl;

    sala[s].atualizarSensores(rand());
  }
  else{
    cout << R"(  
 ____        _          _____ 
/ ___|  __ _| | __ _   |___ / 
\___ \ / _` | |/ _` |    |_ \ 
 ___) | (_| | | (_| |   ___) |
|____/ \__,_|_|\__,_|  |____/  )" << endl << endl;

    sala[s].atualizarSensores(rand());
  }
  

  
  cout << " 1 - Configurar atuadores              3 - Atualizar" << endl;
  cout << " 2 - Voltar" << endl << endl;
  cout << " O que deseja fazer: ";
}

string menuAtuadores(int decisaoSala, Sala sala[3]){
  system("cls");
  int atuadorParaAtualizar;
  string atuadorEscolhido;
  cout << R"(  
 _____     _            _             _                _   _                   _                     
| ____|___| |_ __ _  __| | ___     __| | ___  ___     / \ | |_ _   _  __ _  __| | ___  _ __ ___  ___ 
|  _| / __| __/ _` |/ _` |/ _ \   / _` |/ _ \/ __|   / _ \| __| | | |/ _` |/ _` |/ _ \| '__/ _ \/ __|
| |___\__ \ || (_| | (_| | (_) | | (_| | (_) \__ \  / ___ \ |_| |_| | (_| | (_| | (_) | | |  __/\__ \
|_____|___/\__\__,_|\__,_|\___/   \__,_|\___/|___/ /_/   \_\__|\__,_|\__,_|\__,_|\___/|_|  \___||___/ )" << endl << endl;

  sala[decisaoSala - 1].atualizarAtuadores();
  cout << "Qual sensor deseja atualizar?" << endl;
  cout << " 1 - Lampada                  3 - Umidificador" << endl;
  cout << " 2 - Ventilador               4 - Desumidificador" << endl;
  cout << " 5 - Sair "<< endl << endl;
  cout << " O que deseja fazer: ";
  cin >> atuadorParaAtualizar;
  if(atuadorParaAtualizar == 1){
    atuadorEscolhido = "Lampada";
  }
  else if(atuadorParaAtualizar == 2){
    atuadorEscolhido = "Ventilador";
  }
  else if(atuadorParaAtualizar == 3){
    atuadorEscolhido = "Umidificador";
  }
  else if(atuadorParaAtualizar == 4){
    atuadorEscolhido = "Desumidificador";
  }
  else{
    atuadorEscolhido = "Sair";
  }
  return atuadorEscolhido;
}

int alterarAtuador(int escolherSala, Sala sala[3]){
  system("cls");
  int aletandoAtuador;
  int valor;
  
  cout << R"( 
  ___                             _ _                                            _                   _              ___ 
 / _ \    __ _ _   _  ___    __ _| | |_ ___ _ __ __ _ _ __   _ __   ___     __ _| |_ _   _  __ _  __| | ___  _ __  |__ \
| | | |  / _` | | | |/ _ \  / _` | | __/ _ \ '__/ _` | '__| | '_ \ / _ \   / _` | __| | | |/ _` |/ _` |/ _ \| '__|   / /
| |_| | | (_| | |_| |  __/ | (_| | | ||  __/ | | (_| | |    | | | | (_) | | (_| | |_| |_| | (_| | (_| | (_) | |     |_| 
 \___/   \__, |\__,_|\___|  \__,_|_|\__\___|_|  \__,_|_|    |_| |_|\___/   \__,_|\__|\__,_|\__,_|\__,_|\___/|_|     (_) 
            |_|                                                                                                         )" << endl << endl;
  cout << " 1 - Conectar                  4 - Desligar" << endl;
  cout << " 2 - Desconectar               5 - Alterar o valor" << endl;
  cout << " 3 - Ligar                     6 - Sair "<< endl << endl;
  cout << " O que deseja fazer: ";
  cin >> aletandoAtuador;
  
  if(aletandoAtuador == 1){
    sala[escolherSala - 1].setConectarOuDesconectarAtuador(1);
  }   
  else if(aletandoAtuador == 2){
    sala[escolherSala - 1].setConectarOuDesconectarAtuador(0);
  }  
  else if(aletandoAtuador == 3){
    sala[escolherSala - 1].setLigarOuDesligarAtuador(1);
  }  
  else if(aletandoAtuador == 4){
    sala[escolherSala - 1].setLigarOuDesligarAtuador(0);
  } 
  else if(aletandoAtuador == 5){
    cout << endl << "Para qual valor?";
    cin >> valor;
    sala[escolherSala - 1].setValorNovoDoAtuador(valor);
  }  
  else if(aletandoAtuador == 6){return aletandoAtuador;}
  
  sleep(2);
  
  return aletandoAtuador;
}