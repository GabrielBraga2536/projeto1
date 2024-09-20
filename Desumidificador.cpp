#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Desumidificador: public Atuador{
    private:
        int configuracao;

    public:
        Desumidificador(int configuracao){
        this->configuracao = configuracao;
        }

        bool setConfiguracao(int configuracao){
            if(configuracao == 0){
                return true;
            }

            else{
                return false;
            }
        }

        int getConfiguracaoDesumidificador(){
            return configuracao;
        }

};