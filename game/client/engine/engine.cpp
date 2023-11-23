#include "engine.h"



#define VECT template <typename TypeXY, typename TypeZ, typename Tnm>
#define VEC vec<TypeXY, TypeZ, Tnm>

namespace engine {
    VECT VEC::vec() noexcept {
        this -> x=0;
        this -> y=0;
        this -> z=0;
    }
    VECT VEC::vec(TypeXY x, TypeXY y, TypeZ z) {
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    VECT VEC::vec(TypeXY x, TypeXY y) {
        this -> x = x;
        this -> y = y;
        this -> z = 0;
    }
    VECT VEC::vec(vec& copyData) noexcept {
        x = copyData.x;
        y = copyData.y;
        z = copyData.z;
    }
    VECT VEC& VEC::operator= (vec& newData) noexcept {
        if(*this == newData) return *this;
        x = newData.x;
        y = newData.y;
        z = newData.z;
        return  *this;
    }
    VECT VEC::~vec() {}



    VECT inline TypeXY VEC::getX() const noexcept {return x;}
    VECT inline TypeXY VEC::getY() const noexcept {return y;}
    VECT inline TypeZ  VEC::getZ() const noexcept {return z;}

    VECT inline void VEC::setX(TypeXY newX) noexcept {x = newX;}
    VECT inline void VEC::setY(TypeXY newY) noexcept {y = newY;}
    VECT inline void VEC::setZ(TypeZ  newZ) noexcept {z = newZ;}



    VECT double VEC::getLen() const noexcept {return (double(x*x) + double(y*y) + double(z*z));}
    VECT double VEC::getLen(const vec& centerData) const noexcept
                                    {return (double((x-centerData.x)*(x-centerData.x))
                                             + double((y-centerData.y)*(y-centerData.y))
                                             + double((z-centerData.z)*(z-centerData.z)));}
    VECT double VEC::getDist() const noexcept {return sqrt(this -> getLen());}
    VECT double VEC::getDist(const vec& centerData) const noexcept {return sqrt(this -> getLen(centerData));}



    VECT VEC& VEC::operator+= (const vec& vectorData) noexcept {x += vectorData.x; y += vectorData.y; z += vectorData.z; return *this;}
    VECT VEC& VEC::operator-= (const vec& vectorData) noexcept {x -= vectorData.x; y -= vectorData.y; z -= vectorData.z; return *this;}
    VECT VEC& VEC::operator*= (const vec& vectorData) noexcept {x *= vectorData.x; y *= vectorData.y; z *= vectorData.z; return *this;}
    VECT VEC& VEC::operator*= (const Tnm& integerNum) noexcept {x *= integerNum;   y *= integerNum;   z *= integerNum;   return *this;}
    VECT VEC& VEC::operator/= (const vec& vectorData) {x /= vectorData.x; y /= vectorData.y; z /= vectorData.z; return *this;}
    VECT VEC& VEC::operator/= (const Tnm& integerNum) {x /= integerNum;   y /= integerNum;   z /= integerNum;   return *this;}

    VECT VEC VEC::operator* (const Tnm& integerNum) const noexcept {return vec(x*integerNum,   y*integerNum,   z*integerNum);  }
    VECT VEC VEC::operator/ (const Tnm& integerNum) const          {return vec(x/integerNum,   y/integerNum,   z/integerNum);  }
    VECT VEC VEC::operator* (const vec& vectorData) const noexcept {return vec(x*vectorData.x, y*vectorData.y, z*vectorData.z);}
    VECT VEC VEC::operator/ (const vec& vectorData) const          {return vec(x/vectorData.x, y/vectorData.y, z/vectorData.z);}              //!!!!! Деление 0 на 0! Необходимо выдавать ошибку bad value(vector.[INCORRECT_VALUE_CORD])
    VECT VEC VEC::operator+ (const vec& vectorData) const noexcept {return vec(x+vectorData.x, y-vectorData.x, z-vectorData.z);}
    VECT VEC VEC::operator- (const vec& vectorData) const noexcept {return vec(x-vectorData.x, y-vectorData.y, z-vectorData.z);}



    VECT bool VEC::operator== (const vec& vectorData) const noexcept {return x == vectorData.x && y == vectorData.y && z == vectorData.z;}
    VECT bool VEC::operator!= (const vec& vectorData) const noexcept {return !(*this == vectorData);}
};
VECT std::ostream& operator<< (std::ostream& Out, const engine::vec<TypeXY, TypeZ, Tnm>& Vector) {
    Out << Vector.x << " " << Vector.y << " " << Vector.z;
    return Out;
}
VECT std::istream& operator>> (std::istream&  In, engine::vec<TypeXY, TypeZ, Tnm>& Vector) {
    TypeXY x, y; TypeZ z; In >> x >> y >> z; 
    Vector = engine::vec(x,y,z); return In;
}
//}
#undef VECT
#undef VEC