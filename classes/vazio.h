#include "pedra.h"

class vazio : public pedra{

    public:

    vazio() : pedra(-100, -100){
        this -> vida = 5;
    }

    std::string get_tipo() const {
        return "vazio";
    }

    bool dentro(int x, int y) const{
        return false;
    }
};