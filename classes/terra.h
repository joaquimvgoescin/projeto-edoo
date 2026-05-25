#include "pedra.h"

class terra : public pedra{

    public:

    terra(int posicaox, int posicaoy) : pedra(posicaox,posicaoy){

        this -> vida = 10;
    }

    std::string get_tipo() const {
        return "terra";
    }
};