#include "pedra.h"

class prata : public pedra{

    public:

    prata(int posicaox, int posicaoy) : pedra(posicaox,posicaoy){

        this -> vida = 5;
    }

    std::string get_tipo() const override {
        return "patra";
    }
    ~prata(){}
};