#include <iostream>
#include <stdlib.h>

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
    
    sala[0].atualizarSensores(rand());
  }
  else if(s == 2){
    cout << R"(  
     ____        _          ____  
    / ___|  __ _| | __ _   |___ \ 
    \___ \ / _` | |/ _` |    __) |
     ___) | (_| | | (_| |   / __/ 
    |____/ \__,_|_|\__,_|  |_____| )" << endl << endl;

    sala[1].atualizarSensores(rand());
  }
  else{
    cout << R"(  
     ____        _          _____ 
    / ___|  __ _| | __ _   |___ / 
    \___ \ / _` | |/ _` |    |_ \ 
     ___) | (_| | | (_| |   ___) |
    |____/ \__,_|_|\__,_|  |____/  )" << endl << endl;

    sala[2].atualizarSensores(rand());
  }
  
  
  
  cout << " 1 - Atualizar                 3 - Voltar" << endl;
  cout << " 2 - Configurar atuadores" << endl << endl;
  cout << " O que deseja fazer: ";
}