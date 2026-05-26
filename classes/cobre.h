#include "pedra.h"

class cobre : public pedra{

    public:

    cobre(int posicaox, int posicaoy) : pedra(posicaox,posicaoy){

        this -> vida = 5;
    }

    std::string get_tipo() const {
        return "cobre";
    }
    ~cobre(){}
};