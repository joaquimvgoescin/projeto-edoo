#include <ctime>
#include <cstdlib>
#include <string>
#ifndef _pedra_h_
#define _pedra_h_

class pedra {
    protected:

    int x_centro;
    int y_centro;
    float tamanho = 5;
    float x_esquerda;
    float x_direita;
    float ycima;
    float ybaixo;
    int vida;

    public :
    pedra(int posicaox, int posicaoy){

        this -> x_centro = posicaox;
        this -> y_centro = posicaoy;

        std:: srand(std::time(nullptr));
        x_esquerda = x_centro - tamanho ;
        x_direita = x_centro + tamanho ;
        ybaixo = y_centro - tamanho ;
        ycima = y_centro + tamanho;
    }

    virtual ~pedra(){};

    bool dentro(int x, int y){
        if (x >= this -> x_esquerda && x <= this -> x_direita && y >= this -> ybaixo && y <= this -> ycima){
            return true;
        }
        return false;
    }

    bool dano(){
        this -> vida -= 1;
        if (this -> vida <= 0){
            return true;
        }
        return false;
    }

    virtual std::string get_tipo() const{return "nada";};
};

#endif