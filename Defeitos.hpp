#include <iostream>
using namespace std;

class Defeitos{
  public:
    string mensagem;

// criando o construtor de Defeitos para quando for necessário parar uma função utilizando o "try" e "catch"
  Defeitos(string s){
    mensagem = s;
  }
};