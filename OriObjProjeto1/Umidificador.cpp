#include <iostream>
#include "Atuador.hpp"
using namespace std;

class Umidificador{
    private:
        int configuracao;

    public:
        Umidificador(int configuracao){
        this->configuracao = configuracao;
        }

        bool setConfiguracao(int configuracao){
            if(configuracao == 1){
                return true;
            }

            else{
                return false;
            }
        }

};