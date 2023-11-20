#include "engine.h"

namespace engine {

engine::vec::vec() {
    this -> x=0;
    this -> y=0;
    this -> z=0;
}

engine::vec::vec(short int x, short int y, char z) {
    this -> x = x;
    this -> y = y;
    this -> z = z;
}
engine::vec::vec(short int x, short int y) {
    this -> x = x;
    this -> y = y;
    this -> z = 0;
}
engine::vec& engine::vec::operator= (engine::vec& newData) {
    x = newData.x;
    y = newData.y;
    z = newData.z;
    return  *this;
}
engine::vec::~vec() {}



inline short int engine::vec::getX() {return x;}
inline short int engine::vec::getY() {return y;}
inline char      engine::vec::getZ() {return z;}

void engine::vec::setX(short int newX) {x = newX;}
void engine::vec::setY(short int newY) {y = newY;}
void engine::vec::setZ(char      newZ) {z = newZ;}



std::ostream& operator<< (std::ostream& Out, engine::vec& Vector) {
    Out << Vector.getX() << " " <<
    Vector.getY() << " " << Vector.getZ();
    return Out;
}

std::istream& operator>> (std::istream&  In, engine::vec& Vector) {
    int x, y, z; In >> x >> y >> z; 
    engine::vec Vector_new(x,y,z);
    Vector = Vector_new; return In;
}
}