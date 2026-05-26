#include <vector>
#include "pedra.h"

class perssonagem {
    private:
    int posicaox;
    int posicaoy;
    int minerioferro;
    int minerioprata;
    int minerioouro;

    public:

    perssonagem(){
        std::srand(std::time(nullptr));
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

    void mover_cima(std::vector<std::vector<pedra>>){
        
    }
};