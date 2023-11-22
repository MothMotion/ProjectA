#include "engine.h"

namespace engine {
    template <typename TypeXY = short, typename TypeZ = char, typename Tnm = int>
    vec<TypeXY, TypeZ>::vec() {
        this -> x=0;
        this -> y=0;
        this -> z=0;
    }

    vec<TypeXY, TypeZ>::vec(TypeXY x, TypeXY y, TypeZ z) {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    vec::vec(TypeXY x, TypeXY y) {
        this -> x = x;
        this -> y = y;
        this -> z = 0;
    }
    vec::vec(engine::vec& copyData) {
        x = copyData.x;
        y = copyData.y;
        z = copyData.z;
    }
    vec& vec::operator= (engine::vec& newData) {
        if(*this == newData) return *this;
        x = newData.x;
        y = newData.y;
        z = newData.z;
        return  *this;
    }
    engine::vec::~vec() {}



    inline TypeXY vec::getX() {return x;}
    inline TypeXY vec::getY() {return y;}
    inline TypeZ  vec::getZ() {return z;}

    void vec::setX(TypeXY newX) {x = newX;}
    void vec::setY(TypeXY newY) {y = newY;}
    void vec::setZ(TypeZ  newZ) {z = newZ;}



    double vec::getLen() const {return (double(x*x) + double(y*y) + double(z*z));}
    double vec::getLen(const vec& centerData) const
                                     {return (double((x-centerData.x)*(x-centerData.x))
                                            + double((y-centerData.y)*(y-centerData.y))
                                            + double((z-centerData.z)*(z-centerData.z)));}
    double vec::getDist() const {return sqrt(this -> getLen());}
    double vec::getDist(const vec& centerData) const {return sqrt(this -> getLen(centerData));}



    vec& vec::operator+= (const vec& vectorData) {x += vectorData.x; y += vectorData.y; z += vectorData.z; return *this;}
    vec& vec::operator-= (const vec& vectorData) {x -= vectorData.x; y -= vectorData.y; z -= vectorData.z; return *this;}
    vec& vec::operator*= (const vec& vectorData) {x *= vectorData.x; y *= vectorData.y; z *= vectorData.z; return *this;}
    vec& vec::operator*= (const Tnm& integerNum) {x *= integerNum;   y *= integerNum;   z *= integerNum;   return *this;}
    vec& vec::operator/= (const vec& vectorData) {x /= vectorData.x; y /= vectorData.y; z /= vectorData.z; return *this;}
    vec& vec::operator/= (const Tnm& integerNum) {x /= integerNum;   y /= integerNum;   z /= integerNum;   return *this;}

    vec vec::operator* (const Tnm& integerNum) const {return vec(x*integerNum,   y*integerNum,   z*integerNum);  }
    vec vec::operator/ (const Tnm& integerNum) const {return vec(x/integerNum,   y/integerNum,   z/integerNum);  }
    vec vec::operator* (const vec& vectorData) const {return vec(x*vectorData.x, y*vectorData.y, z*vectorData.z);}
    vec vec::operator/ (const vec& vectorData) const {return vec(x/vectorData.x, y/vectorData.y, z/vectorData.z);}              //!!!!! Деление 0 на 0! Необходимо выдавать ошибку bad value(vector.[INCORRECT_VALUE_CORD])
    vec vec::operator+ (const vec& vectorData) const {return vec(x+vectorData.x, y-vectorData.x, z-vectorData.z);}
    vec vec::operator- (const vec& vectorData) const {return vec(x-vectorData.x, y-vectorData.y, z-vectorData.z);}



    bool vec::operator== (const vec& vectorData) const {return x == vectorData.x && y == vectorData.y && z == vectorData.z;}
    bool vec::operator!= (const vec& vectorData) const {return !(*this == vectorData);}



    std::ostream& operator<< (std::ostream& Out, const vec& Vector) {
        Out << Vector.x << " " <<
        Vector.y << " " << Vector.z;
        return Out;
    }

    std::istream& operator>> (std::istream&  In, vec& Vector) {
        short x, y, z; In >> x >> y >> z; 
        vec Vector_new(x,y,z);
        Vector = Vector_new; return In;
    }
}

//int main() {return 0;}