#include "engine.h"

namespace engine {
    vec::vec() {
        this -> x=0;
        this -> y=0;
        this -> z=0;
    }

    vec::vec(short int x, short int y, char z) {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    vec::vec(short int x, short int y) {
        this -> x = x;
        this -> y = y;
        this -> z = 0;
    }
    vec& vec::operator= (engine::vec& newData) {
        if(*this == newData) return *this;
        x = newData.x;
        y = newData.y;
        z = newData.z;
        return  *this;
    }
    engine::vec::~vec() {}



    inline short int vec::getX() {return x;}
    inline short int vec::getY() {return y;}
    inline char      vec::getZ() {return z;}

    void vec::setX(short int newX) {x = newX;}
    void vec::setY(short int newY) {y = newY;}
    void vec::setZ(char      newZ) {z = newZ;}



    vec& vec::operator+= (vec& vectorData) {x += vectorData.x; y += vectorData.y; z += vectorData.z; return *this;}
    vec& vec::operator-= (vec& vectorData) {x -= vectorData.x; y -= vectorData.y; z -= vectorData.z; return *this;}
    vec& vec::operator*= (vec& vectorData) {x *= vectorData.x; y *= vectorData.y; z *= vectorData.z; return *this;}
    vec& vec::operator*= (int& integerNum) {x *= integerNum;   y *= integerNum;   z *= integerNum;   return *this;}
    vec& vec::operator/= (vec& vectorData) {x /= vectorData.x; y /= vectorData.y; z /= vectorData.z; return *this;}
    vec& vec::operator/= (int& integerNum) {x /= integerNum;   y /= integerNum;   z /= integerNum;   return *this;}

    vec vec::operator* (const int& integerNum) const {return vec(x*integerNum,   y*integerNum,   z*integerNum);  }
    vec vec::operator/ (const int& integerNum) const {return vec(x/integerNum,   y/integerNum,   z/integerNum);  }
    vec vec::operator* (const vec& vectorData) const {return vec(x*vectorData.x, y/vectorData.y, z/vectorData.z);}
    vec vec::operator/ (const vec& vectorData) const {return vec(x/vectorData.x, y/vectorData.y, z/vectorData.z);}

    bool vec::operator== (vec& vectorData) const {return x == vectorData.x && y == vectorData.y && z == vectorData.z;}
    bool vec::operator!= (vec& vectorData) const {return !(*this == vectorData);}

    std::ostream& operator<< (std::ostream& Out, const vec& Vector) {
        Out << Vector.x << " " <<
        Vector.y << " " << Vector.z;
        return Out;
    }

    std::istream& operator>> (std::istream&  In, vec& Vector) {
        int x, y, z; In >> x >> y >> z; 
        vec Vector_new(x,y,z);
        Vector = Vector_new; return In;
    }
}

//int main() {return 0;}