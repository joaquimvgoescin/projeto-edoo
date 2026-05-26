#include <vector>
#include "pedra.h"
#include "variaveis_constantes.h"
#include "vazio.h"

class perssonagem {
    private:
    int posicaox;
    int posicaoy;
    int mineriocobre;
    int minerioprata;
    int minerioouro;
    int perssonagem_velocidade = velocidade;
    int delay;
    const int tempo_delay = 5;

    int* caminho_bloqueado(const std::vector<std::vector<pedra*>> &meu_mapa, int novo_x, int novo_y){
        int saida[2] = {-1,-1};
        for(int i = 0; i < dimencao_mapay; i++){
            for(int j = 0; j < dimencao_mapax; j++){

                if((*meu_mapa[i][j]).dentro(novo_x,novo_y)){
                    saida[0] = i;
                    saida[1] = j;
                    return saida;
                }
            }
        }
        return saida;
    }

    void minerar(std::vector<std::vector<pedra*>> &meu_mapa, int i, int j){
        if((*(meu_mapa[i][j])).dano()){
            std::string minerio_coletadoA = (*meu_mapa[i][j]).get_tipo();
            if(minerio_coletadoA == "cobre"){this -> mineriocobre += 1;}  
            if(minerio_coletadoA == "prata"){this -> minerioprata += 1;}
            if(minerio_coletadoA == "ouro"){this -> minerioouro += 1;}
            
            delete meu_mapa[i][j];
            meu_mapa[i][j] = new vazio();
        }
    }

    public:

    perssonagem(int x, int y){
        this -> posicaox = x;
        this -> posicaoy = y;
        mineriocobre = 0;
        minerioprata = 0;
        minerioouro = 0;
        delay = 0;
    }
    int get_x() const{
        return posicaox;
    }

    int get_y() const {
        return posicaoy;
    }
    int* get_minerios() const{
        int x[3] = {mineriocobre, minerioprata, minerioouro};
        return x;
    }

    void mover_cima(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaoy < dimencao_mapay * tamanho_bloco){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox, this -> posicaoy + this -> perssonagem_velocidade);
            this -> delay = this -> tempo_delay;

            if(resultado[0] == -1){
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
            this -> delay = this -> tempo_delay;
            
            if(resultado[0] == -1){
                this -> posicaoy -= this -> perssonagem_velocidade;
            }

            else {
                minerar(meu_mapa, resultado[0], resultado[1]);

            }
        }
    }

    void mover_direita(std::vector<std::vector<pedra*>> &meu_mapa){
        if(delay <= 0 && posicaox < dimencao_mapax * tamanho_bloco){
            int* resultado = caminho_bloqueado(meu_mapa, this -> posicaox + this -> perssonagem_velocidade, this -> posicaoy);
            this -> delay = this -> tempo_delay;

            if(resultado[0] == -1){
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
            this -> delay = this -> tempo_delay;

            if(resultado[0] == -1){
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