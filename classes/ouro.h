#include "pedra.h"

class ouro : public pedra{

    public:
    ouro(int posicaox, int posicaoy) : pedra(posicaox, posicaoy){

        this -> vida = 5;
    }

    std::string get_tipo() const {
        return "ouro";
    }
    ~ouro(){}
};