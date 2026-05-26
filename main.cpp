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

int main(){
    //gera seed
    std::srand(std::time(nullptr));

    //gerar mapa
    std::vector<std::vector<pedra*>> mapa;
    std:: vector<pedra*> vector_vazio_vector;
    for(int i = 1; i <= dimencao_mapay; i++){
        mapa.push_back(vector_vazio_vector);

        for (int j = 1; j <= dimencao_mapax; j++){
            int numero_aleatorio = std::rand() % 10 ;
            if (numero_aleatorio == 1){
                mapa[i - 1].push_back(new pedra(ouro(j * tamanho_bloco,i * tamanho_bloco)));
            }

            else if (numero_aleatorio == 2){
                mapa[i - 1].push_back(new pedra(prata(j * tamanho_bloco,i * tamanho_bloco)));
            }

            else if (numero_aleatorio == 2){
                mapa[i - 1].push_back(new pedra(cobre(j * tamanho_bloco,i * tamanho_bloco)));
            }

            else{
                mapa[i - 1].push_back(new pedra(terra(j * tamanho_bloco,i * tamanho_bloco)));
            }
            
            
        }
    }
    return 0;
}