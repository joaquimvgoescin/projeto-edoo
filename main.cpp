#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classes/ouro.h"
#include "classes/cobre.h"
#include "classes/prata.h"
#include "classes/terra.h"
#include "classes/pedra.h"
#include "variaveis_constantes.h"
#include "classes/perssonagem.h"
// para pausar

#include <thread>
#include <chrono>

int main(){
    //gera seed
    std::srand(std::time(nullptr));

    //gerar mapa
    std::vector<std::vector<pedra*>> mapa;
    std:: vector<pedra*> vector_vazio_vector;
    for(int i = 1; i <= dimencao_mapay; i++){
        mapa.push_back(vector_vazio_vector);

        for (int j = 1; j <= dimencao_mapax; j++){
            int numero_aleatorio = (std::rand() * i * j) % 7 ;
            if (numero_aleatorio == 1){
                mapa[i - 1].push_back(new cobre(j * tamanho_bloco - 5,i * tamanho_bloco - 5));
            }

            else if (numero_aleatorio == 2){
                mapa[i - 1].push_back(new prata(j * tamanho_bloco - 5,i * tamanho_bloco - 5));
            }

            else if (numero_aleatorio == 3){
                mapa[i - 1].push_back(new ouro(j * tamanho_bloco - 5,i * tamanho_bloco - 5));
            }

            else{
                mapa[i - 1].push_back(new terra(j * tamanho_bloco - 5,i * tamanho_bloco - 5));
            }
            
            
        }
    }

    //criar perssonagens
    perssonagem perssonagem1(1,1);
    perssonagem perssonagem2(dimencao_mapax - 1, 1);
    

    // deleta tiles aonde os perssonagens nacem.
    delete mapa[0][0];
    mapa[0][0] = new vazio();
    delete mapa[0][dimencao_mapax - 1];
    mapa[0][dimencao_mapax - 1] = new vazio();


    
    //inicio
    while(true){

        bool botao_a = false;
        bool botao_d = true;
        bool botao_w = false;
        bool botao_s = false;
        bool botao_esquerda = false;
        bool botao_direita = false;
        bool botao_cima = false;
        bool botao_baixo = false;

        void (perssonagem :: *lista_andar[4])(std::vector<std::vector<pedra*>> &) = {&perssonagem :: mover_baixo, &perssonagem:: mover_cima, &perssonagem :: mover_direita, &perssonagem :: mover_esquerda};
        bool lista1_bool1[4] = {botao_s, botao_w, botao_d, botao_a};
        bool lista1_bool2[4] = {botao_baixo, botao_cima, botao_direita, botao_esquerda};

        for(int i = 0; i < 4; i++){


            if(lista1_bool1[i]){

                (perssonagem1.*lista_andar[i])(mapa);
            }

            if(lista1_bool2[i]){

                (perssonagem2.*lista_andar[i])(mapa);
            }

        }
        perssonagem1.atualizar();
        perssonagem2.atualizar();
        std :: this_thread :: sleep_for(std :: chrono:: milliseconds(16));
    }


    return 0;
}