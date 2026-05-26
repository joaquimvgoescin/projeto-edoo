#include <vector>
#include "pedra.h"
#include "variaveis_constantes.h"
#include "vazio.h"

class perssonagem {
    private:
    int posicaox;
    int posicaoy;
    int minerioferro;
    int minerioprata;
    int minerioouro;
    int perssonagem_velocidade = velocidade;
    int delay;

    int* caminho_bloqueado(const std::vector<std::vector<pedra*>> &meu_mapa, int novo_x, int novo_y){
        for(int i = 1; i <= dimencao_mapay; i++){
            for(int j = 1; j <= dimencao_mapax; j++){

                if((*meu_mapa[i][j]).dentro(novo_x,novo_y)){
                    int saida[2] = {i,j};
                    return saida;
                }
            }
        }
        int saida[1] = {0};
        return saida;
    }

    void minerar(std::vector<std::vector<pedra*>> &meu_mapa, int i, int j){
        if((*(meu_mapa[i][j])).dano()){
            *meu_mapa[i][j] = pedra(vazio());
        }
    }

    public:

    perssonagem(int x, int y){
        this -> posicaox = x;
        this -> posicaoy = y;
    }
    int get_x(){
        return posicaox;
    }

    int get_y(){
        return posicaoy;
    }
    int* get_minerios(){
        int x[3] = {minerioferro, minerioprata, minerioouro};
        return x;
    }

    void mover_cima(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaoy < dimencao_mapay){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox, this -> posicaoy + this -> perssonagem_velocidade);
            
            if(resultado[0] == 0){
                this -> posicaoy += this -> perssonagem_velocidade;
            }

            else {
                minerar(meu_mapa, resultado[0], resultado[1]);

            }
        }
    }


    void mover_baixo(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaoy > 0){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox, this -> posicaoy - this -> perssonagem_velocidade);
            
            if(resultado[0] == 0){
                this -> posicaoy -= this -> perssonagem_velocidade;
            }

            else {
                minerar(meu_mapa, resultado[0], resultado[1]);

            }
        }
    }

    void mover_direita(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaox < dimencao_mapax){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox + this -> perssonagem_velocidade, this -> posicaoy);
            
            if(resultado[0] == 0){
                this -> posicaox += this -> perssonagem_velocidade;
            }

            else {
                minerar(meu_mapa, resultado[0], resultado[1]);

            }
        }
    }

    void mover_esquerda(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaox > 0){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox - this -> perssonagem_velocidade, this -> posicaoy);
            
            if(resultado[0] == 0){
                this -> posicaox -= this -> perssonagem_velocidade;
            }

            else {
                minerar(meu_mapa, resultado[0], resultado[1]);

            }
        }
    }

    void atualizar(){

        if(delay >= 0){
            delay--;
        }
    }

};